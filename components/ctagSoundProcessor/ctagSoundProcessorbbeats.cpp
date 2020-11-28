/***************
CTAG TBD >>to be determined<< is an open source eurorack synthesizer module.

A project conceived within the Creative Technologies Arbeitsgruppe of
Kiel University of Applied Sciences: https://www.creative-technologies.de
(c) 2020 by Robert Manzke. All rights reserved.

(c) 2020 by Mathias Brüssel for "ByteBeatsXFade"-Plugin. All rights reserved.
Includes ByteBeat algorithms by Matt Wand - make sure to have a look at his other great work at: hot-air.bandcamp.com

The CTAG TBD software is licensed under the GNU General Public License
(GPL 3.0), available here: https://www.gnu.org/licenses/gpl-3.0.txt

The CTAG TBD hardware design is released under the Creative Commons
Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0).
Details here: https://creativecommons.org/licenses/by-nc-sa/4.0/

CTAG TBD is provided "as is" without any express or implied warranties.

License and copyright details for specific submodules are included in their
respective component folders / files if different from this license.
***************/

#include "ctagSoundProcessorbbeats.hpp"

using namespace CTAG::SP;

// data.buf[i * 2 + processCh] = (float)((byte)(t & 128));    // Square wave, working ok!

// --- Helper function: rescale CV or Pot to integer of given range 0...max ---
inline int ctagSoundProcessorbbeats::process_param( const ProcessData &data, int cv_myparm, int my_parm, int parm_range, int max_idx )
{
  if (cv_myparm != -1)
  {
    if( data.cv[cv_myparm] >= 0.0 )       // This is a bypass solution to avoid negative values in rare cases
      return (int)(data.cv[cv_myparm] * parm_range);
    else
      return 0;
  }
  else
    return my_parm * parm_range / max_idx;
}

// --- Helper function: rescale CV or Pot to float 0...1.0 (CV is already in correct format, we still keep it inside this method for convenience ---
inline float ctagSoundProcessorbbeats::process_param_float( const ProcessData &data, int cv_myparm, int my_parm, int max_idx )
{
  if(cv_myparm != -1)
  {
    if (data.cv[cv_myparm] >= 0.0f)     // This is a bypass solution to avoid negative values in rare cases
      return data.cv[cv_myparm];
    else
      return 0.0f;
  }
  else
    return my_parm / (float)max_idx;
}


inline bool ctagSoundProcessorbbeats::process_param_bool( const ProcessData &data, int trig_myparm, int my_parm, int prev_trig_state_id )
{
  if (trig_myparm != -1)
  {
    if( data.trig[trig_myparm] != prev_trig_state[prev_trig_state_id] )
    {
      if (data.trig[trig_myparm] > 0 )     // This is a bypass solution to avoid negative values in rare cases
        prev_trig_state[prev_trig_state_id] = data.trig[trig_myparm];   // Trigger was different from as last time, remember new value
      else
        prev_trig_state[prev_trig_state_id] = 1;                        // Trigger is off when 1!
    }
  }
  else
  {
    (my_parm) ? prev_trig_state[prev_trig_state_id] = 0 : prev_trig_state[prev_trig_state_id] = 1;  // Set Trigger to 0 if on from GUI
  }
  if( prev_trig_state[prev_trig_state_id] == 0 )                        // Trigger is on when 0!
    return true;
  else
    return false;
}

// --- Helper function: provide logic operations on bytebeats ---
inline float ctagSoundProcessorbbeats::logic_operation_on_beat()
{
  switch( logic_operation_id )
  {
    case 0:   // Or operation
      return ((beat_byte_A | beat_byte_B)-127)/127.0f;

    case 1:   // NOR A operation
      return ((~beat_byte_A | beat_byte_B)-127)/127.0f;

    case 2:   // NOR B operation
      return ((beat_byte_A | ~beat_byte_B)-127)/127.0f;

    case 3:   // NOR A-B operation
      return ((~beat_byte_A | ~beat_byte_B)-127)/127.0f;


    case 4:   // And operation
      return ((beat_byte_A & beat_byte_B)-127)/127.0f;

    case 5:   // NAND A operation
      return ((~beat_byte_A & beat_byte_B)-127)/127.0f;

    case 6:   // NAND B operation
      return ((beat_byte_A & ~beat_byte_B)-127)/127.0f;

    case 7:   // NAND A-B operation
      return ((~beat_byte_A & ~beat_byte_B)-127)/127.0f;


    case 8:   // XOR operation
      return ((beat_byte_A ^ beat_byte_B)-127)/127.0f;

    case 9:   // N-XOR  A operation
      return ((~beat_byte_A ^ beat_byte_B)-127)/127.0f;

    case 10:   // N-XOR B operation
      return ((beat_byte_A ^ ~beat_byte_B)-127)/127.0f;

    case 11:   // N-XOR A-B operation
      return ((~beat_byte_A ^ ~beat_byte_B)-127)/127.0f;


    case 12:   // Special case: return "left" ByteBeat to optimize transition to regular crossfading, because we use the lower half for our logical operation
      return (beat_byte_A-127)/127.0f;


    default: // ByteBeatA as result again, just in case, as a "catch all" ;-)
      // printf("Encountered unexpected Id %d for bitwise operation on ByteBeats\n", logic_operation_id );
      return (beat_byte_A-127)/127.0f;
  }
}


void ctagSoundProcessorbbeats::Process(const ProcessData &data)
{
  // --- Read triggers or bools from GUI about every 3 milliseconds and buffer results as private member variables ---
  if( ++cv_counter%11 == 0 )
  {
    // --- Read and buffer options for ByteBeat A ---
    stop_beatA = process_param_bool( data, trig_beatA_stop, beatA_stop, e_stop_beatA );
    reset_beatA = process_param_bool( data, trig_beatA_reset_on_stop, beatA_reset_on_stop, e_reset_beatA );
    reverse_beatA = process_param_bool( data, trig_beatA_backwards, beatA_backwards, e_reverse_beatA );

    // --- Read and buffer option for ByteBeat B ---
    stop_beatB = process_param_bool( data, trig_beatB_stop, beatB_stop, e_stop_beatB );
    reset_beatB = process_param_bool( data, trig_beatB_reset_on_stop, beatB_reset_on_stop, e_reset_beatB );
    reverse_beatB = process_param_bool( data, trig_beatB_backwards, beatB_backwards, e_reverse_beatB );

    // --- Read and buffer option for XFade-mode ---
    logic_mixes_allowed = process_param_bool(data, trig_allow_logic_mixes, allow_logic_mixes, e_logic_mixes_allowed );
  }
  // --- Read controllers from GUI or CV about every 16 milliseconds and buffer results as private member variables ---
  if( ++cv_counter%100 == 0 )
  {
    // --- Read and buffer controllers for ByteBeat A ---
    if( stop_beatA && reset_beatA )
      reverse_beatA ? t1 = -1 : t1 = 1;      // reset incrementor for bytebeat algorithms, avoid 0 to not devide by zero
    beat_index_A = process_param( data,cv_beatA_select, beatA_select, BEAT_A_MAX_IDX, BEAT_A_MAX_IDX );
    slow_down_A_factor = 129 - process_param( data,cv_beatA_pitch, beatA_pitch, 128, 128 );

    // --- Read and buffer controllers for ByteBeat B ---
    if( stop_beatB && reset_beatB )
      reverse_beatB ? t2 = -1 : t2 = 1;    // reset incrementor for bytebeat algorithms, avoid 0 to not devide by zero
    beat_index_B = process_param( data,cv_beatB_select, beatB_select, BEAT_B_MAX_IDX, BEAT_B_MAX_IDX );
    slow_down_B_factor = 129 - process_param( data,cv_beatB_pitch, beatB_pitch, 128, 128 );

    // --- Read and buffer controllers for mixing ByteBeat A with ByteBeat B ---
    if( logic_mixes_allowed )
    {
      if (cv_xFadeA_B != -1)
        data.cv[cv_xFadeA_B] >= 0.0  ? xfade_val_int = (int)(data.cv[cv_xFadeA_B] * 4095) : xfade_val_int = 0;
      else
        xfade_val_int = xFadeA_B;

      if( xfade_val_int < 2048 )                       // Use logical operation in first half of range of pot
        logic_operation_id = (int)(xfade_val_int * 13 / 2047);  // We multiply with 13 instead of normally 12, to avoid rounding errors with narrow range here
      else
        xfade_val = (xfade_val_int-2048)/2047.0f;        // We expand 50%-100% of pot to 0-100% for normal crossfade
    }
    else
      xfade_val = process_param_float(data, cv_xFadeA_B, xFadeA_B, 4095);
  }
  // --- This is our main loop, where the generation and mixing of ByteBeats takes place ---
  for (uint32_t i = 0; i < bufSz; i++)
  {
    // --- Process ByteBeat A ---
    if (slow_down_A >= slow_down_A_factor)
    {
      slow_down_A = 0;
      if( t1==0 )
        reverse_beatA ? t1-- : t1++;    // Avoid devision by zero for some algos
      if( !stop_beatA )
      {
        beat_byte_A = beats_P1[beat_index_A](t1);       // We may will also need the numeric value for logic operations on the ByteBeats
        beat_val_A = (float) (beat_byte_A - 127) / 127.0f; // beat_val_A: private member, so we buffer the result
        reverse_beatA ? t1-- : t1++;   // Decrement or increment iterator for ByteBeat1 algorithm
      }
    }
    slow_down_A++;  // We increment a counter for Beat1 every loop, so we can decide with next loop if we generate a new valur

    // --- Process ByteBeat B ---
    if (slow_down_B >= slow_down_B_factor)
    {
      slow_down_B = 0;
      if( t2==0 )
        reverse_beatA ? t2-- : t2++;    // Avoid devision by zero for some algos
      if( !stop_beatB )
      {
        beat_byte_B = beats_P2[beat_index_B](t2);       // We may will also need the numeric value for logic operations on the ByteBeats
        beat_val_B = (float)(beat_byte_B - 127) / 127.0f; // beat_val_B: private member, so we buffer the result
        reverse_beatB ? t2-- : t2++;   // Decrement or increment iterator for ByteBeat1 algorithm
      }
    }
    slow_down_B++;  // We increment a counter for Beat1 every loop, so we can decide with next loop if we generate a new valur

    // --- Mix ByteBeat A and ByteBeat B (in the first quarter of the Pot's range optionally logical operations may be performed on the beats  ---
    if( logic_mixes_allowed == true )     // Check for normal crossfade or additional logic operations for Pot for first quarter of range...
    {
      if( xfade_val_int <= 2047 )         // We are in the lower 50% of the Pot or GUI slider
        data.buf[i*2 + processCh] = logic_operation_on_beat();                              // Perform logical operations on ByteBeats in first 50% of PorRange for XFade!
      else                                                                                    // We already rescaled the xfade_val when reading controllers!
        data.buf[i*2 + processCh] = beat_val_A*(1.0f-xfade_val) + beat_val_B*xfade_val;        // Mix both ByteBeats, depending on XFade-factor
    }
    else
      data.buf[i*2 + processCh] = beat_val_A*(1.0f-xfade_val) + beat_val_B*xfade_val;         // Mix both ByteBeats, depending on XFade-factor
  }
}

ctagSoundProcessorbbeats::ctagSoundProcessorbbeats()
{
  // construct internal data model
  knowYourself();
  model = std::make_unique<ctagSPDataModel>(id, isStereo);
  LoadPreset(0);
}

ctagSoundProcessorbbeats::~ctagSoundProcessorbbeats()
{
}

void ctagSoundProcessorbbeats::knowYourself()
{
  // autogenerated code here
  // sectionCpp0
  pMapPar.emplace("beatA_reset_on_stop", [&](const int val){ beatA_reset_on_stop = val;});
  pMapTrig.emplace("beatA_reset_on_stop", [&](const int val){ trig_beatA_reset_on_stop = val;});
  pMapPar.emplace("beatA_stop", [&](const int val){ beatA_stop = val;});
  pMapTrig.emplace("beatA_stop", [&](const int val){ trig_beatA_stop = val;});
  pMapPar.emplace("beatA_backwards", [&](const int val){ beatA_backwards = val;});
  pMapTrig.emplace("beatA_backwards", [&](const int val){ trig_beatA_backwards = val;});
  pMapPar.emplace("beatA_select", [&](const int val){ beatA_select = val;});
  pMapCv.emplace("beatA_select", [&](const int val){ cv_beatA_select = val;});
  pMapPar.emplace("beatA_pitch", [&](const int val){ beatA_pitch = val;});
  pMapCv.emplace("beatA_pitch", [&](const int val){ cv_beatA_pitch = val;});
  pMapPar.emplace("beatB_reset_on_stop", [&](const int val){ beatB_reset_on_stop = val;});
  pMapTrig.emplace("beatB_reset_on_stop", [&](const int val){ trig_beatB_reset_on_stop = val;});
  pMapPar.emplace("beatB_stop", [&](const int val){ beatB_stop = val;});
  pMapTrig.emplace("beatB_stop", [&](const int val){ trig_beatB_stop = val;});
  pMapPar.emplace("beatB_backwards", [&](const int val){ beatB_backwards = val;});
  pMapTrig.emplace("beatB_backwards", [&](const int val){ trig_beatB_backwards = val;});
  pMapPar.emplace("beatB_select", [&](const int val){ beatB_select = val;});
  pMapCv.emplace("beatB_select", [&](const int val){ cv_beatB_select = val;});
  pMapPar.emplace("beatB_pitch", [&](const int val){ beatB_pitch = val;});
  pMapCv.emplace("beatB_pitch", [&](const int val){ cv_beatB_pitch = val;});
  pMapPar.emplace("allow_logic_mixes", [&](const int val){ allow_logic_mixes = val;});
  pMapTrig.emplace("allow_logic_mixes", [&](const int val){ trig_allow_logic_mixes = val;});
  pMapPar.emplace("xFadeA_B", [&](const int val){ xFadeA_B = val;});
  pMapCv.emplace("xFadeA_B", [&](const int val){ cv_xFadeA_B = val;});

  isStereo = false;
  id = "bbeats";
  // sectionCpp0
}