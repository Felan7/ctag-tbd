EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title "CTAG TBD Eurorack Audio Module"
Date "2020-03-18"
Rev "B"
Comp "(c) Robert Manzke 2020"
Comment1 "https://creativecommons.org/licenses/by-nc-sa/4.0/"
Comment2 "Licensed under CC BY-NC-SA 4.0"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Q_NPN_BEC Q?
U 1 1 5B81BF2F
P 8150 1650
AR Path="/5B66F258/5B81BF2F" Ref="Q?"  Part="1" 
AR Path="/5B81850F/5B81BF2F" Ref="Q301"  Part="1" 
F 0 "Q301" H 8341 1696 50  0000 L CNN
F 1 "SS8050-G" H 8341 1605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8350 1750 50  0001 C CNN
F 3 "~" H 8150 1650 50  0001 C CNN
	1    8150 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BEC Q?
U 1 1 5B81BF36
P 8150 2450
AR Path="/5B66F258/5B81BF36" Ref="Q?"  Part="1" 
AR Path="/5B81850F/5B81BF36" Ref="Q302"  Part="1" 
F 0 "Q302" H 8341 2404 50  0000 L CNN
F 1 "SS8050-G" H 8341 2495 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8350 2550 50  0001 C CNN
F 3 "~" H 8150 2450 50  0001 C CNN
	1    8150 2450
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5B81BF3D
P 7600 1650
AR Path="/5B66F258/5B81BF3D" Ref="R?"  Part="1" 
AR Path="/5B81850F/5B81BF3D" Ref="R302"  Part="1" 
F 0 "R302" V 7393 1650 50  0000 C CNN
F 1 "10k" V 7484 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7530 1650 50  0001 C CNN
F 3 "~" H 7600 1650 50  0001 C CNN
	1    7600 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5B81BF44
P 7600 2450
AR Path="/5B66F258/5B81BF44" Ref="R?"  Part="1" 
AR Path="/5B81850F/5B81BF44" Ref="R303"  Part="1" 
F 0 "R303" V 7393 2450 50  0000 C CNN
F 1 "10k" V 7484 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7530 2450 50  0001 C CNN
F 3 "~" H 7600 2450 50  0001 C CNN
	1    7600 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	7950 1650 7750 1650
Wire Wire Line
	7950 2450 7750 2450
Wire Wire Line
	8250 1850 8250 2000
Wire Wire Line
	8250 2000 7250 2000
Wire Wire Line
	7250 2000 7250 2450
Wire Wire Line
	7250 2450 7450 2450
Wire Wire Line
	8250 2250 8250 2150
Wire Wire Line
	7350 2150 7350 1650
Wire Wire Line
	7350 1650 7450 1650
Wire Wire Line
	8250 1250 8250 1450
Wire Wire Line
	8250 2650 8250 2850
Connection ~ 7350 1650
Wire Wire Line
	7250 2450 6900 2450
Connection ~ 7250 2450
Text Label 6900 1650 0    50   ~ 0
DTR
Text Label 6900 2450 0    50   ~ 0
RTS
$Comp
L power:+3.3V #PWR?
U 1 1 5B81BF68
P 5000 900
AR Path="/5B66F258/5B81BF68" Ref="#PWR?"  Part="1" 
AR Path="/5B81850F/5B81BF68" Ref="#PWR0301"  Part="1" 
F 0 "#PWR0301" H 5000 750 50  0001 C CNN
F 1 "+3.3V" H 5015 1073 50  0000 C CNN
F 2 "" H 5000 900 50  0001 C CNN
F 3 "" H 5000 900 50  0001 C CNN
	1    5000 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 900  5000 1000
Text Label 4450 1800 0    50   ~ 0
D+
Wire Wire Line
	4600 1800 4450 1800
Text Label 4450 1900 0    50   ~ 0
D-
Wire Wire Line
	4450 1900 4600 1900
Wire Wire Line
	5100 1100 5100 1000
Wire Wire Line
	5100 1000 5000 1000
Connection ~ 5000 1000
Wire Wire Line
	5000 1000 5000 1100
Text Label 5900 1800 2    50   ~ 0
DTR
Text Label 5900 1400 2    50   ~ 0
RTS
Wire Wire Line
	5600 1800 5900 1800
Text HLabel 9000 1250 2    50   Output ~ 0
EN
Text HLabel 9000 2850 2    50   Output ~ 0
IO0
Text HLabel 5750 1500 2    50   Output ~ 0
TXD
Text HLabel 6350 1600 2    50   Input ~ 0
RXD
Wire Wire Line
	5600 1400 5900 1400
Wire Wire Line
	5600 1500 5750 1500
Wire Wire Line
	8250 1250 9000 1250
Wire Wire Line
	6900 1650 7350 1650
Wire Wire Line
	8250 2850 9000 2850
$Comp
L Device:C C?
U 1 1 5B6712E4
P 3700 3100
AR Path="/5B66F258/5B6712E4" Ref="C?"  Part="1" 
AR Path="/5B81850F/5B6712E4" Ref="C301"  Part="1" 
F 0 "C301" H 3815 3146 50  0000 L CNN
F 1 "10u" H 3815 3055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 3738 2950 50  0001 C CNN
F 3 "~" H 3700 3100 50  0001 C CNN
	1    3700 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3350 3700 3450
Connection ~ 3700 3350
Wire Wire Line
	4100 3350 3700 3350
Wire Wire Line
	4100 3250 4100 3350
Wire Wire Line
	3700 2850 3700 2950
Connection ~ 3700 2850
Wire Wire Line
	4100 2850 3700 2850
Wire Wire Line
	4100 2950 4100 2850
$Comp
L Device:C C?
U 1 1 5B81C017
P 4100 3100
AR Path="/5B66F258/5B81C017" Ref="C?"  Part="1" 
AR Path="/5B81850F/5B81C017" Ref="C302"  Part="1" 
F 0 "C302" H 4215 3146 50  0000 L CNN
F 1 "100n" H 4215 3055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4138 2950 50  0001 C CNN
F 3 "~" H 4100 3100 50  0001 C CNN
	1    4100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3250 3700 3350
$Comp
L power:GND #PWR?
U 1 1 5B81C010
P 3700 3450
AR Path="/5B66F258/5B81C010" Ref="#PWR?"  Part="1" 
AR Path="/5B81850F/5B81C010" Ref="#PWR0304"  Part="1" 
F 0 "#PWR0304" H 3700 3200 50  0001 C CNN
F 1 "GND" H 3705 3277 50  0000 C CNN
F 2 "" H 3700 3450 50  0001 C CNN
F 3 "" H 3700 3450 50  0001 C CNN
	1    3700 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2750 3700 2850
$Comp
L power:+3.3V #PWR?
U 1 1 5B81C002
P 3700 2750
AR Path="/5B66F258/5B81C002" Ref="#PWR?"  Part="1" 
AR Path="/5B81850F/5B81C002" Ref="#PWR0303"  Part="1" 
F 0 "#PWR0303" H 3700 2600 50  0001 C CNN
F 1 "+3.3V" H 3715 2923 50  0000 C CNN
F 2 "" H 3700 2750 50  0001 C CNN
F 3 "" H 3700 2750 50  0001 C CNN
	1    3700 2750
	1    0    0    -1  
$EndComp
Text Label 3550 2000 2    50   ~ 0
D-
Text Label 3550 1900 2    50   ~ 0
D+
$Comp
L power:GND #PWR?
U 1 1 5B81BF8A
P 5100 3800
AR Path="/5B66F258/5B81BF8A" Ref="#PWR?"  Part="1" 
AR Path="/5B81850F/5B81BF8A" Ref="#PWR0305"  Part="1" 
F 0 "#PWR0305" H 5100 3550 50  0001 C CNN
F 1 "GND" H 5105 3627 50  0000 C CNN
F 2 "" H 5100 3800 50  0001 C CNN
F 3 "" H 5100 3800 50  0001 C CNN
	1    5100 3800
	1    0    0    -1  
$EndComp
$Comp
L Interface_USB:CP2102N-A01-GQFN28 U301
U 1 1 5DAABA1C
P 5100 2400
F 0 "U301" H 4700 3700 50  0000 C CNN
F 1 "CP2102N-A01-GQFN28" V 4800 2050 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_5x5mm_P0.5mm_EP3.35x3.35mm" H 5550 1200 50  0001 L CNN
F 3 "https://www.silabs.com/documents/public/data-sheets/cp2102n-datasheet.pdf" H 5150 1650 50  0001 C CNN
	1    5100 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3700 5100 3800
NoConn ~ 5600 1300
NoConn ~ 5600 1700
NoConn ~ 5600 1900
NoConn ~ 5600 2000
NoConn ~ 5600 2200
NoConn ~ 5600 2300
NoConn ~ 5600 2500
NoConn ~ 5600 2600
NoConn ~ 5600 2700
NoConn ~ 5600 2900
NoConn ~ 5600 3000
NoConn ~ 5600 3100
NoConn ~ 5600 3200
NoConn ~ 5600 3300
NoConn ~ 5600 3400
NoConn ~ 5600 3500
Wire Wire Line
	7350 2150 8250 2150
NoConn ~ 3350 2100
Wire Wire Line
	3350 1900 3550 1900
Wire Wire Line
	3550 2000 3350 2000
$Comp
L Connector:USB_B_Micro J?
U 1 1 5B81BF77
P 3050 1900
AR Path="/5B66F258/5B81BF77" Ref="J?"  Part="1" 
AR Path="/5B81850F/5B81BF77" Ref="J301"  Part="1" 
F 0 "J301" H 3105 2367 50  0000 C CNN
F 1 "USB_B_Micro" H 3105 2276 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 3200 1850 50  0001 C CNN
F 3 "~" H 3200 1850 50  0001 C CNN
	1    3050 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5B81BF7F
P 3050 2650
AR Path="/5B66F258/5B81BF7F" Ref="#PWR?"  Part="1" 
AR Path="/5B81850F/5B81BF7F" Ref="#PWR0302"  Part="1" 
F 0 "#PWR0302" H 3050 2400 50  0001 C CNN
F 1 "GND" H 3055 2477 50  0000 C CNN
F 2 "" H 3050 2650 50  0001 C CNN
F 3 "" H 3050 2650 50  0001 C CNN
	1    3050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2300 3050 2400
Wire Wire Line
	3050 2400 2950 2400
Wire Wire Line
	2950 2400 2950 2300
Connection ~ 3050 2400
Wire Wire Line
	3050 2400 3050 2650
NoConn ~ 4600 1500
$Comp
L Device:R R301
U 1 1 5DBD0908
P 6100 1600
F 0 "R301" V 5893 1600 50  0000 C CNN
F 1 "470R" V 5984 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6030 1600 50  0001 C CNN
F 3 "~" H 6100 1600 50  0001 C CNN
	1    6100 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 1600 5600 1600
Wire Wire Line
	6250 1600 6350 1600
Wire Wire Line
	3350 1700 4600 1700
$EndSCHEMATC