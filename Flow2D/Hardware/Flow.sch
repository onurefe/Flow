EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:VDD #PWR019
U 1 1 6075738F
P 8300 3950
F 0 "#PWR019" H 8300 3800 50  0001 C CNN
F 1 "VDD" H 8250 4100 50  0000 C CNN
F 2 "" H 8300 3950 50  0001 C CNN
F 3 "" H 8300 3950 50  0001 C CNN
	1    8300 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3950 8300 4000
$Comp
L Device:C_Small C10
U 1 1 6075A94A
P 8150 4150
F 0 "C10" V 8250 4000 50  0000 L CNN
F 1 "100n" V 8150 3950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8150 4150 50  0001 C CNN
F 3 "~" H 8150 4150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 8150 4150 50  0001 C CNN "Link"
F 5 "0.00499" H 8150 4150 50  0001 C CNN "Price"
	1    8150 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 607608FC
P 7950 4150
F 0 "#PWR018" H 7950 3900 50  0001 C CNN
F 1 "GND" H 7800 4150 50  0000 C CNN
F 2 "" H 7950 4150 50  0001 C CNN
F 3 "" H 7950 4150 50  0001 C CNN
	1    7950 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4000 8300 4000
Connection ~ 8300 4000
Wire Wire Line
	8300 4000 8300 4150
Wire Wire Line
	8250 4150 8300 4150
Wire Wire Line
	8050 4000 8000 4000
Wire Wire Line
	8000 4000 8000 4100
Wire Wire Line
	8000 4150 8050 4150
$Comp
L power:GND #PWR07
U 1 1 6076CF34
P 5700 3100
F 0 "#PWR07" H 5700 2850 50  0001 C CNN
F 1 "GND" H 5705 2927 50  0000 C CNN
F 2 "" H 5700 3100 50  0001 C CNN
F 3 "" H 5700 3100 50  0001 C CNN
	1    5700 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 607703D4
P 4900 2600
F 0 "#PWR04" H 4900 2450 50  0001 C CNN
F 1 "+5V" H 4915 2773 50  0000 C CNN
F 2 "" H 4900 2600 50  0001 C CNN
F 3 "" H 4900 2600 50  0001 C CNN
	1    4900 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR08
U 1 1 6077111C
P 6200 2600
F 0 "#PWR08" H 6200 2450 50  0001 C CNN
F 1 "VDD" H 6215 2773 50  0000 C CNN
F 2 "" H 6200 2600 50  0001 C CNN
F 3 "" H 6200 2600 50  0001 C CNN
	1    6200 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 607DC2B6
P 6400 9050
F 0 "#PWR014" H 6400 8800 50  0001 C CNN
F 1 "GND" H 6405 8877 50  0000 C CNN
F 2 "" H 6400 9050 50  0001 C CNN
F 3 "" H 6400 9050 50  0001 C CNN
	1    6400 9050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 607DDB32
P 6550 8350
F 0 "C6" V 6450 8600 50  0000 C CNN
F 1 "100n" V 6450 8350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6550 8350 50  0001 C CNN
F 3 "~" H 6550 8350 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 6550 8350 50  0001 C CNN "Link"
F 5 "0.00499" H 6550 8350 50  0001 C CNN "Price"
	1    6550 8350
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 8300 6400 8350
Wire Wire Line
	6450 8350 6400 8350
Connection ~ 6400 8350
Wire Wire Line
	6400 8350 6400 8400
$Comp
L power:GND #PWR015
U 1 1 607E2057
P 6700 8400
F 0 "#PWR015" H 6700 8150 50  0001 C CNN
F 1 "GND" H 6800 8400 50  0000 C CNN
F 2 "" H 6700 8400 50  0001 C CNN
F 3 "" H 6700 8400 50  0001 C CNN
	1    6700 8400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 8350 6700 8350
Wire Wire Line
	6700 8350 6700 8400
Wire Wire Line
	6400 9000 6400 9050
$Comp
L power:GND #PWR016
U 1 1 60918E04
P 6900 4900
F 0 "#PWR016" H 6900 4650 50  0001 C CNN
F 1 "GND" H 6900 4750 50  0000 C CNN
F 2 "" H 6900 4900 50  0001 C CNN
F 3 "" H 6900 4900 50  0001 C CNN
	1    6900 4900
	1    0    0    -1  
$EndComp
Text Label 11500 4650 0    50   ~ 0
OUT_X
$Comp
L Device:C_Small C14
U 1 1 60EFEE04
P 11050 4850
F 0 "C14" H 11000 4700 50  0000 L CNN
F 1 "10u" H 10950 4800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 11050 4850 50  0001 C CNN
F 3 "~" H 11050 4850 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A106MQ8NNNC" H 11050 4850 50  0001 C CNN "Link"
F 5 "0.01596" H 11050 4850 50  0001 C CNN "Price"
	1    11050 4850
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR024
U 1 1 60F0325F
P 11050 5000
F 0 "#PWR024" H 11050 4750 50  0001 C CNN
F 1 "GND" H 10950 5000 50  0000 C CNN
F 2 "" H 11050 5000 50  0001 C CNN
F 3 "" H 11050 5000 50  0001 C CNN
	1    11050 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	11050 5000 11050 4950
Wire Wire Line
	10950 4650 11050 4650
Wire Wire Line
	11050 4650 11050 4750
$Comp
L Device:R_Small R24
U 1 1 60F1F4B3
P 11250 4650
F 0 "R24" V 11300 4650 50  0000 C CNN
F 1 "12k" V 11200 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 11250 4650 50  0001 C CNN
F 3 "~" H 11250 4650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 11250 4650 50  0001 C CNN "Link"
F 5 "0.0019" H 11250 4650 50  0001 C CNN "Price"
	1    11250 4650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR026
U 1 1 60F210C6
P 11400 5000
F 0 "#PWR026" H 11400 4750 50  0001 C CNN
F 1 "GND" H 11300 5000 50  0000 C CNN
F 2 "" H 11400 5000 50  0001 C CNN
F 3 "" H 11400 5000 50  0001 C CNN
	1    11400 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 4900 11400 5000
Wire Wire Line
	11150 4650 11050 4650
Connection ~ 11050 4650
Wire Wire Line
	11350 4650 11400 4650
Wire Wire Line
	11400 4650 11400 4700
Wire Wire Line
	11500 4650 11400 4650
Connection ~ 11400 4650
$Comp
L oe_flow:LR9102G U2
U 1 1 609369DE
P 5700 2750
F 0 "U2" H 5700 3117 50  0000 C CNN
F 1 "LR9102G" H 5700 3026 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 5700 2850 50  0001 C CNN
F 3 "" H 5700 2850 50  0001 C CNN
F 4 "https://ozdisan.com/Product/Detail/497420/LR9102G-33-AE5-R" H 5700 2750 50  0001 C CNN "Link"
F 5 "0.09595" H 5700 2750 50  0001 C CNN "Price"
	1    5700 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 6094003F
P 6200 2950
F 0 "#PWR09" H 6200 2700 50  0001 C CNN
F 1 "GND" H 6205 2777 50  0000 C CNN
F 2 "" H 6200 2950 50  0001 C CNN
F 3 "" H 6200 2950 50  0001 C CNN
	1    6200 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2900 6200 2950
Wire Wire Line
	6200 2600 6200 2650
Wire Wire Line
	6100 2650 6200 2650
Connection ~ 6200 2650
Wire Wire Line
	6200 2650 6200 2700
Wire Wire Line
	5700 3050 5700 3100
$Comp
L power:GND #PWR05
U 1 1 6095CEA4
P 4900 3000
F 0 "#PWR05" H 4900 2750 50  0001 C CNN
F 1 "GND" H 4905 2827 50  0000 C CNN
F 2 "" H 4900 3000 50  0001 C CNN
F 3 "" H 4900 3000 50  0001 C CNN
	1    4900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2900 4900 2950
Connection ~ 4900 2650
Wire Wire Line
	4900 2650 4900 2700
Wire Wire Line
	4900 2650 5000 2650
Wire Wire Line
	5300 2850 5250 2850
Wire Wire Line
	5050 2850 5000 2850
Wire Wire Line
	5000 2850 5000 2650
Connection ~ 5000 2650
Wire Wire Line
	5000 2650 5300 2650
$Comp
L Device:R_Small R8
U 1 1 60AA86AA
P 5150 2850
F 0 "R8" V 5250 2850 50  0000 C CNN
F 1 "12k" V 5350 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5150 2850 50  0001 C CNN
F 3 "~" H 5150 2850 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 5150 2850 50  0001 C CNN "Link"
F 5 "0.0019" H 5150 2850 50  0001 C CNN "Price"
	1    5150 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 2700 4750 2650
Wire Wire Line
	4750 2650 4900 2650
Wire Wire Line
	4750 2900 4750 2950
Wire Wire Line
	4750 2950 4900 2950
Wire Wire Line
	4900 2950 4900 3000
Connection ~ 4900 2950
$Comp
L power:+5V #PWR028
U 1 1 60B0ACEF
P 11550 2900
F 0 "#PWR028" H 11550 2750 50  0001 C CNN
F 1 "+5V" H 11500 3050 50  0000 C CNN
F 2 "" H 11550 2900 50  0001 C CNN
F 3 "" H 11550 2900 50  0001 C CNN
	1    11550 2900
	1    0    0    -1  
$EndComp
Text Label 7250 4400 2    50   ~ 0
SWCLK
Text Label 9300 5500 0    50   ~ 0
SWDIO
Text Label 10950 3050 2    50   ~ 0
SWCLK
Text Label 7300 4300 2    50   ~ 0
NRST
$Comp
L Device:C_Small C4
U 1 1 60BD0344
P 6200 2800
F 0 "C4" H 6000 2800 50  0000 L CNN
F 1 "1u" H 6000 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6200 2800 50  0001 C CNN
F 3 "~" H 6200 2800 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A105KP8NNNC" H 6200 2800 50  0001 C CNN "Link"
F 5 "0.00742" H 6200 2800 50  0001 C CNN "Price"
	1    6200 2800
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R11
U 1 1 60BD6B60
P 7050 4800
F 0 "R11" V 7150 4700 50  0000 C CNN
F 1 "12k" V 7150 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7050 4800 50  0001 C CNN
F 3 "~" H 7050 4800 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 7050 4800 50  0001 C CNN "Link"
F 5 "0.0019" H 7050 4800 50  0001 C CNN "Price"
	1    7050 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2600 4900 2650
$Comp
L Device:C_Small C7
U 1 1 609CE773
P 7050 4700
F 0 "C7" V 6950 4600 50  0000 C CNN
F 1 "100n" V 6950 4800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7050 4700 50  0001 C CNN
F 3 "~" H 7050 4700 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 7050 4700 50  0001 C CNN "Link"
F 5 "0.00499" H 7050 4700 50  0001 C CNN "Price"
	1    7050 4700
	0    1    1    0   
$EndComp
$Comp
L Device:Speaker_Ultrasound LS1
U 1 1 60861A60
P 3700 5250
F 0 "LS1" H 4000 5400 50  0000 C CNN
F 1 "Speaker_Ultrasound" H 4000 5500 50  0000 C CNN
F 2 "oe_ultrasonic:GU1007C-40TR" H 3665 5200 50  0001 C CNN
F 3 "~" H 3665 5200 50  0001 C CNN
F 4 "https://lcsc.com/product-detail/_INGHAi-GU1007C-40TR_C242175.html" H 3700 5250 50  0001 C CNN "Link"
F 5 "1.27" H 3700 5250 50  0001 C CNN "Price"
	1    3700 5250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3900 5250 3950 5250
Wire Wire Line
	3950 5250 3950 5150
Wire Wire Line
	3950 5150 4000 5150
Wire Wire Line
	3900 5350 3950 5350
Wire Wire Line
	3950 5350 3950 5450
Wire Wire Line
	3950 5450 4000 5450
$Comp
L power:GND #PWR02
U 1 1 60F3B0D4
P 3600 4800
F 0 "#PWR02" H 3600 4550 50  0001 C CNN
F 1 "GND" H 3750 4800 50  0000 C CNN
F 2 "" H 3600 4800 50  0001 C CNN
F 3 "" H 3600 4800 50  0001 C CNN
	1    3600 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4750 3600 4800
$Comp
L Device:C_Small C1
U 1 1 60F4254F
P 3750 4000
F 0 "C1" V 3950 4000 50  0000 C CNN
F 1 "100n" V 3850 4000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3750 4000 50  0001 C CNN
F 3 "~" H 3750 4000 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 3750 4000 50  0001 C CNN "Link"
F 5 "0.00499" H 3750 4000 50  0001 C CNN "Price"
	1    3750 4000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 60F43823
P 3900 4050
F 0 "#PWR03" H 3900 3800 50  0001 C CNN
F 1 "GND" H 4050 4050 50  0000 C CNN
F 2 "" H 3900 4050 50  0001 C CNN
F 3 "" H 3900 4050 50  0001 C CNN
	1    3900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3950 3600 4000
Wire Wire Line
	3650 4000 3600 4000
Connection ~ 3600 4000
Wire Wire Line
	3600 4000 3600 4050
Wire Wire Line
	3850 4000 3900 4000
Wire Wire Line
	3900 4000 3900 4050
$Comp
L oe_flow:SN74LVC2G17 U1
U 3 1 60FF5F23
P 3600 4400
F 0 "U1" H 4050 4350 50  0000 C CNN
F 1 "SN74LVC2G17" H 4050 4450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3600 4400 50  0001 C CNN
F 3 "~" H 3600 4400 50  0001 C CNN
F 4 "https://ozdisan.com/Product/Detail/461876/SN74LVC2G17DBVR" H 3600 4400 50  0001 C CNN "Link"
F 5 "0.25423" H 3600 4400 50  0001 C CNN "Price"
	3    3600 4400
	1    0    0    -1  
$EndComp
$Comp
L oe_stm32:STM32G030F6Px U4
U 1 1 60FF94CB
P 8300 5050
F 0 "U4" H 8850 5900 50  0000 C CNN
F 1 "STM32G030F6Px" H 8850 6000 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 8300 5050 50  0001 C CNN
F 3 "~" H 8300 5050 50  0001 C CNN
F 4 "https://lcsc.com/product-detail/ST-Microelectronics_STMicroelectronics-STM32G030F6P6TR_C529330.html" H 8300 5050 50  0001 C CNN "Link"
F 5 "1.7546" H 8300 5050 50  0001 C CNN "Price"
	1    8300 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 6102A65D
P 8300 5950
F 0 "#PWR020" H 8300 5700 50  0001 C CNN
F 1 "GND" H 8305 5777 50  0000 C CNN
F 2 "" H 8300 5950 50  0001 C CNN
F 3 "" H 8300 5950 50  0001 C CNN
	1    8300 5950
	1    0    0    -1  
$EndComp
Text Label 9300 5200 0    50   ~ 0
PULSE
Text Label 9300 5100 0    50   ~ 0
PULSE_N
Wire Wire Line
	9250 5100 9300 5100
Wire Wire Line
	9250 5200 9300 5200
Wire Wire Line
	8300 5900 8300 5950
Wire Wire Line
	6900 4700 6900 4800
Connection ~ 6900 4800
Wire Wire Line
	6900 4800 6900 4900
Wire Wire Line
	6950 4700 6900 4700
Wire Wire Line
	6900 4800 6950 4800
Wire Wire Line
	7150 4700 7300 4700
Wire Wire Line
	7350 4800 7250 4800
Wire Wire Line
	7300 4300 7300 4700
Connection ~ 7300 4700
Wire Wire Line
	7300 4700 7350 4700
Wire Wire Line
	7250 4400 7250 4800
Connection ~ 7250 4800
Wire Wire Line
	7250 4800 7150 4800
NoConn ~ 7350 5000
NoConn ~ 7350 5100
Wire Wire Line
	8300 4150 8300 4200
Connection ~ 8300 4150
Wire Wire Line
	7950 4150 7950 4100
Wire Wire Line
	7950 4100 8000 4100
Connection ~ 8000 4100
Wire Wire Line
	8000 4100 8000 4150
Wire Wire Line
	9300 5500 9250 5500
Text Label 9300 4400 0    50   ~ 0
CHA_A
Text Label 9300 4500 0    50   ~ 0
CHA_B
Text Label 9300 4600 0    50   ~ 0
CHA_C
Wire Wire Line
	9300 4400 9250 4400
Wire Wire Line
	9300 4500 9250 4500
Wire Wire Line
	9300 4600 9250 4600
Text Label 9300 5300 0    50   ~ 0
PWM_Y
Text Label 9300 5400 0    50   ~ 0
PWM_X
Wire Wire Line
	9300 5300 9250 5300
Wire Wire Line
	9300 5600 9250 5600
NoConn ~ 9250 4700
NoConn ~ 9250 4800
NoConn ~ 9250 4900
NoConn ~ 9250 5000
Text Label 10700 4650 2    50   ~ 0
PWM_X
Wire Wire Line
	10750 4650 10700 4650
Wire Wire Line
	6650 7550 6600 7550
Wire Wire Line
	6600 7550 6600 7750
Wire Wire Line
	6600 7750 7300 7750
Wire Wire Line
	7300 7750 7300 7450
Wire Wire Line
	7300 7450 7250 7450
$Comp
L Device:C_Small C5
U 1 1 61358BC2
P 6250 7650
F 0 "C5" H 6200 7700 50  0000 L CNN
F 1 "1u" H 6200 7600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6250 7650 50  0001 C CNN
F 3 "~" H 6250 7650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A105KP8NNNC" H 6250 7650 50  0001 C CNN "Link"
F 5 "0.00742" H 6250 7650 50  0001 C CNN "Price"
	1    6250 7650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 7350 6400 7350
Wire Wire Line
	6250 7350 6250 7550
Wire Wire Line
	6400 7550 6400 7350
Connection ~ 6400 7350
Wire Wire Line
	6400 7350 6250 7350
Wire Wire Line
	6400 7250 6400 7350
$Comp
L power:GND #PWR012
U 1 1 6137A043
P 6400 7800
F 0 "#PWR012" H 6400 7550 50  0001 C CNN
F 1 "GND" H 6405 7627 50  0000 C CNN
F 2 "" H 6400 7800 50  0001 C CNN
F 3 "" H 6400 7800 50  0001 C CNN
	1    6400 7800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 6137AC89
P 6250 7800
F 0 "#PWR010" H 6250 7550 50  0001 C CNN
F 1 "GND" H 6255 7627 50  0000 C CNN
F 2 "" H 6250 7800 50  0001 C CNN
F 3 "" H 6250 7800 50  0001 C CNN
	1    6250 7800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 7750 6250 7800
Wire Wire Line
	6400 7750 6400 7800
Wire Wire Line
	6400 7000 6400 7050
Text Label 7650 7450 0    50   ~ 0
VGND
Wire Wire Line
	7350 7450 7300 7450
Connection ~ 7300 7450
$Comp
L Device:Speaker_Ultrasound LS2
U 1 1 6141103C
P 3700 6000
F 0 "LS2" H 4000 5750 50  0000 C CNN
F 1 "Speaker_Ultrasound" H 4000 5650 50  0000 C CNN
F 2 "oe_ultrasonic:GU1007C-40TR" H 3665 5950 50  0001 C CNN
F 3 "~" H 3665 5950 50  0001 C CNN
F 4 "1.27" H 3700 6000 50  0001 C CNN "Price"
F 5 "https://lcsc.com/product-detail/_INGHAi-GU1007C-40TR_C242175.html" H 3700 6000 50  0001 C CNN "Link"
	1    3700 6000
	-1   0    0    1   
$EndComp
Text Label 4200 6050 0    50   ~ 0
VGND
$Comp
L power:VDD #PWR011
U 1 1 614F81B1
P 6400 7000
F 0 "#PWR011" H 6400 6850 50  0001 C CNN
F 1 "VDD" H 6300 7100 50  0000 C CNN
F 2 "" H 6400 7000 50  0001 C CNN
F 3 "" H 6400 7000 50  0001 C CNN
	1    6400 7000
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR013
U 1 1 614F8D82
P 6400 8300
F 0 "#PWR013" H 6400 8150 50  0001 C CNN
F 1 "VDD" H 6300 8400 50  0000 C CNN
F 2 "" H 6400 8300 50  0001 C CNN
F 3 "" H 6400 8300 50  0001 C CNN
	1    6400 8300
	1    0    0    -1  
$EndComp
Text Label 11550 3150 0    50   ~ 0
OUT_X
Text Label 11550 3250 0    50   ~ 0
OUT_Y
Text Label 9300 5600 0    50   ~ 0
USART_TX
Wire Wire Line
	9300 5400 9250 5400
Text Label 9300 5700 0    50   ~ 0
USART_RX
Wire Wire Line
	9300 5700 9250 5700
Text Label 10950 3250 2    50   ~ 0
USART_RX
$Comp
L Device:C_Small C8
U 1 1 6170734F
P 7600 7600
F 0 "C8" H 7692 7646 50  0000 L CNN
F 1 "10u" H 7692 7555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7600 7600 50  0001 C CNN
F 3 "~" H 7600 7600 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A106MQ8NNNC" H 7600 7600 50  0001 C CNN "Link"
F 5 "0.01596" H 7600 7600 50  0001 C CNN "Price"
	1    7600 7600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 61707DA5
P 7600 7800
F 0 "#PWR017" H 7600 7550 50  0001 C CNN
F 1 "GND" H 7605 7627 50  0000 C CNN
F 2 "" H 7600 7800 50  0001 C CNN
F 3 "" H 7600 7800 50  0001 C CNN
	1    7600 7800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 7450 7600 7450
Wire Wire Line
	7600 7450 7600 7500
Wire Wire Line
	7600 7700 7600 7800
Wire Wire Line
	7650 7450 7600 7450
Connection ~ 7600 7450
Text Label 10950 3350 2    50   ~ 0
USART_TX
$Comp
L power:VDD #PWR030
U 1 1 60FFCEC7
P 11650 2900
F 0 "#PWR030" H 11650 2750 50  0001 C CNN
F 1 "VDD" H 11700 3050 50  0000 C CNN
F 2 "" H 11650 2900 50  0001 C CNN
F 3 "" H 11650 2900 50  0001 C CNN
	1    11650 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J1
U 1 1 611E115B
P 11200 3150
F 0 "J1" H 11200 3550 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 11200 3650 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x05_P2.54mm_Horizontal" H 11200 3150 50  0001 C CNN
F 3 "~" H 11200 3150 50  0001 C CNN
F 4 "https://ozdisan.com/konnektor-ve-baglanti-elemanlari/header-konnektorler/pin-headerlar/DS1022-2X5R61" H 11200 3150 50  0001 C CNN "Link"
F 5 "0.05624" H 11200 3150 50  0001 C CNN "Price"
	1    11200 3150
	1    0    0    -1  
$EndComp
Text Label 10950 3150 2    50   ~ 0
SWDIO
$Comp
L power:GND #PWR029
U 1 1 60B4A648
P 11550 3400
F 0 "#PWR029" H 11550 3150 50  0001 C CNN
F 1 "GND" H 11555 3227 50  0000 C CNN
F 2 "" H 11550 3400 50  0001 C CNN
F 3 "" H 11550 3400 50  0001 C CNN
	1    11550 3400
	1    0    0    -1  
$EndComp
Text Label 10950 2950 2    50   ~ 0
NRST
Wire Wire Line
	11500 2950 11550 2950
Wire Wire Line
	11550 2950 11550 2900
Wire Wire Line
	11500 3050 11650 3050
Wire Wire Line
	11650 3050 11650 2900
Wire Wire Line
	11500 3350 11550 3350
Wire Wire Line
	11550 3350 11550 3400
Wire Wire Line
	11550 3150 11500 3150
Wire Wire Line
	11550 3250 11500 3250
Wire Wire Line
	10950 2950 11000 2950
Wire Wire Line
	10950 3050 11000 3050
Wire Wire Line
	10950 3150 11000 3150
Wire Wire Line
	10950 3250 11000 3250
Wire Wire Line
	10950 3350 11000 3350
$Comp
L power:+5V #PWR01
U 1 1 61283AEB
P 3600 3950
F 0 "#PWR01" H 3600 3800 50  0001 C CNN
F 1 "+5V" H 3615 4123 50  0000 C CNN
F 2 "" H 3600 3950 50  0001 C CNN
F 3 "" H 3600 3950 50  0001 C CNN
	1    3600 3950
	1    0    0    -1  
$EndComp
Text Label 11500 5200 0    50   ~ 0
OUT_Y
$Comp
L Device:C_Small C15
U 1 1 60F47929
P 11050 5400
F 0 "C15" H 11000 5250 50  0000 L CNN
F 1 "10u" H 10950 5350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 11050 5400 50  0001 C CNN
F 3 "~" H 11050 5400 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A106MQ8NNNC" H 11050 5400 50  0001 C CNN "Link"
F 5 "0.01596" H 11050 5400 50  0001 C CNN "Price"
	1    11050 5400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR025
U 1 1 60F4792F
P 11050 5550
F 0 "#PWR025" H 11050 5300 50  0001 C CNN
F 1 "GND" H 10950 5550 50  0000 C CNN
F 2 "" H 11050 5550 50  0001 C CNN
F 3 "" H 11050 5550 50  0001 C CNN
	1    11050 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	11050 5550 11050 5500
Wire Wire Line
	10950 5200 11050 5200
Wire Wire Line
	11050 5200 11050 5300
$Comp
L Device:R_Small R25
U 1 1 60F47938
P 11250 5200
F 0 "R25" V 11300 5200 50  0000 C CNN
F 1 "12k" V 11200 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 11250 5200 50  0001 C CNN
F 3 "~" H 11250 5200 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 11250 5200 50  0001 C CNN "Link"
F 5 "0.0019" H 11250 5200 50  0001 C CNN "Price"
	1    11250 5200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR027
U 1 1 60F47944
P 11400 5550
F 0 "#PWR027" H 11400 5300 50  0001 C CNN
F 1 "GND" H 11300 5550 50  0000 C CNN
F 2 "" H 11400 5550 50  0001 C CNN
F 3 "" H 11400 5550 50  0001 C CNN
	1    11400 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 5450 11400 5550
Wire Wire Line
	11150 5200 11050 5200
Connection ~ 11050 5200
Wire Wire Line
	11350 5200 11400 5200
Wire Wire Line
	11400 5200 11400 5250
Wire Wire Line
	11500 5200 11400 5200
Connection ~ 11400 5200
Text Label 10700 5200 2    50   ~ 0
PWM_Y
Wire Wire Line
	10750 5200 10700 5200
$Comp
L Device:Opamp_Quad_Generic U3
U 4 1 60F6CC8E
P 8950 8100
F 0 "U3" H 8950 8300 50  0000 C CNN
F 1 "TLV9064IDR" H 8950 8400 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 8950 8100 50  0001 C CNN
F 3 "~" H 8950 8100 50  0001 C CNN
F 4 "https://ozdisan.com/entegre-devreler-ics/lineer-entegreler/amplifikatorler/TLV9064IDR" H 8950 8100 50  0001 C CNN "Link"
F 5 "0.77646" H 8950 8100 50  0001 C CNN "Price"
	4    8950 8100
	1    0    0    -1  
$EndComp
$Comp
L Device:Opamp_Quad_Generic U3
U 5 1 60F6DBAD
P 6300 8700
F 0 "U3" H 6450 8800 50  0000 C CNN
F 1 "TLV9064IDR" H 6450 8700 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6300 8700 50  0001 C CNN
F 3 "~" H 6300 8700 50  0001 C CNN
F 4 "https://ozdisan.com/entegre-devreler-ics/lineer-entegreler/amplifikatorler/TLV9064IDR" H 6300 8700 50  0001 C CNN "Link"
F 5 "0.77646" H 6300 8700 50  0001 C CNN "Price"
	5    6300 8700
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 61004973
P 4000 5950
F 0 "R1" H 4100 6000 50  0000 C CNN
F 1 "12k" H 4100 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4000 5950 50  0001 C CNN
F 3 "~" H 4000 5950 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 4000 5950 50  0001 C CNN "Link"
F 5 "0.0019" H 4000 5950 50  0001 C CNN "Price"
	1    4000 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6000 3950 6000
Wire Wire Line
	3950 6000 3950 6050
Wire Wire Line
	3950 6050 4000 6050
Connection ~ 4000 6050
Wire Wire Line
	4000 6050 4200 6050
Wire Wire Line
	3900 5900 3950 5900
Wire Wire Line
	3950 5900 3950 5850
Wire Wire Line
	3950 5850 4000 5850
Connection ~ 4000 5850
$Comp
L Device:CP_Small C2
U 1 1 60859EC4
P 4750 2800
F 0 "C2" H 4450 2750 50  0000 L CNN
F 1 "47u 10v" H 4350 2850 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-21_Kemet-B_Pad1.50x2.35mm_HandSolder" H 4750 2800 50  0001 C CNN
F 3 "~" H 4750 2800 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/tantal-kondansatorler/TSK1A476TSSR" H 4750 2800 50  0001 C CNN "Link"
F 5 "0.15882" H 4750 2800 50  0001 C CNN "Price"
	1    4750 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 7650 9350 7650
Wire Wire Line
	9350 7650 9350 7350
Wire Wire Line
	9350 7350 9300 7350
Wire Wire Line
	8700 7450 8650 7450
Wire Wire Line
	8650 7450 8650 7650
Wire Wire Line
	8900 7650 8650 7650
Wire Wire Line
	9050 8400 9300 8400
Wire Wire Line
	9300 8400 9300 8100
Wire Wire Line
	9300 8100 9250 8100
Wire Wire Line
	8650 8200 8600 8200
Wire Wire Line
	8600 8200 8600 8400
Wire Wire Line
	8850 8400 8600 8400
Text Label 8600 8000 2    50   ~ 0
SIGNAL_B
Wire Wire Line
	8650 8000 8600 8000
$Comp
L Device:R_Small R21
U 1 1 6110DA0A
P 9500 7350
F 0 "R21" V 9400 7450 50  0000 C CNN
F 1 "18R" V 9400 7300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9500 7350 50  0001 C CNN
F 3 "~" H 9500 7350 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 9500 7350 50  0001 C CNN "Link"
F 5 "0.00196" H 9500 7350 50  0001 C CNN "Price"
	1    9500 7350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C11
U 1 1 6110EC66
P 9600 8250
F 0 "C11" H 9692 8296 50  0000 L CNN
F 1 "100n" H 9692 8205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9600 8250 50  0001 C CNN
F 3 "~" H 9600 8250 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 9600 8250 50  0001 C CNN "Link"
F 5 "0.00499" H 9600 8250 50  0001 C CNN "Price"
	1    9600 8250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 6110FB2E
P 9650 7650
F 0 "#PWR023" H 9650 7400 50  0001 C CNN
F 1 "GND" H 9750 7650 50  0000 C CNN
F 2 "" H 9650 7650 50  0001 C CNN
F 3 "" H 9650 7650 50  0001 C CNN
	1    9650 7650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 6111005F
P 9600 8400
F 0 "#PWR021" H 9600 8150 50  0001 C CNN
F 1 "GND" H 9700 8400 50  0000 C CNN
F 2 "" H 9600 8400 50  0001 C CNN
F 3 "" H 9600 8400 50  0001 C CNN
	1    9600 8400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 8100 9300 8100
Connection ~ 9300 8100
Wire Wire Line
	9550 8100 9600 8100
Wire Wire Line
	9600 8100 9600 8150
Wire Wire Line
	9600 8350 9600 8400
Wire Wire Line
	9400 7350 9350 7350
Connection ~ 9350 7350
Wire Wire Line
	9600 7350 9650 7350
Wire Wire Line
	9650 7350 9650 7400
Wire Wire Line
	9650 7600 9650 7650
Wire Wire Line
	8650 7650 8600 7650
Connection ~ 8650 7650
Wire Wire Line
	8550 8400 8600 8400
Connection ~ 8600 8400
Text Label 9750 7350 0    50   ~ 0
CHA_A
Text Label 9700 8100 0    50   ~ 0
CHA_B
Wire Wire Line
	9600 8100 9700 8100
Connection ~ 9600 8100
Wire Wire Line
	9650 7350 9750 7350
Connection ~ 9650 7350
Text Label 8300 8400 2    50   ~ 0
VGND
Text Label 8350 7650 2    50   ~ 0
VGND
Wire Wire Line
	8350 7650 8400 7650
Wire Wire Line
	8350 8400 8300 8400
$Comp
L Device:Opamp_Quad_Generic U3
U 1 1 61090EA9
P 8950 8850
F 0 "U3" H 8950 9050 50  0000 C CNN
F 1 "TLV9064IDR" H 8950 9150 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 8950 8850 50  0001 C CNN
F 3 "~" H 8950 8850 50  0001 C CNN
F 4 "https://ozdisan.com/entegre-devreler-ics/lineer-entegreler/amplifikatorler/TLV9064IDR" H 8950 8850 50  0001 C CNN "Link"
F 5 "0.77646" H 8950 8850 50  0001 C CNN "Price"
	1    8950 8850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 7250 8650 7250
Text Label 8650 7250 2    50   ~ 0
SIGNAL_A
$Comp
L Device:R_Small R19
U 1 1 60F38C00
P 9450 8100
F 0 "R19" V 9350 8200 50  0000 C CNN
F 1 "18R" V 9350 8050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9450 8100 50  0001 C CNN
F 3 "~" H 9450 8100 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 9450 8100 50  0001 C CNN "Link"
F 5 "0.00196" H 9450 8100 50  0001 C CNN "Price"
	1    9450 8100
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C13
U 1 1 60F39C5E
P 9650 7500
F 0 "C13" H 9742 7546 50  0000 L CNN
F 1 "100n" H 9742 7455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9650 7500 50  0001 C CNN
F 3 "~" H 9650 7500 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 9650 7500 50  0001 C CNN "Link"
F 5 "0.00499" H 9650 7500 50  0001 C CNN "Price"
	1    9650 7500
	1    0    0    -1  
$EndComp
$Comp
L Device:Opamp_Quad_Generic U3
U 2 1 60F6BA2F
P 6950 7450
F 0 "U3" H 6950 7650 50  0000 C CNN
F 1 "TLV9064IDR" H 6950 7750 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6950 7450 50  0001 C CNN
F 3 "~" H 6950 7450 50  0001 C CNN
F 4 "https://ozdisan.com/entegre-devreler-ics/lineer-entegreler/amplifikatorler/TLV9064IDR" H 6950 7450 50  0001 C CNN "Link"
F 5 "0.77646" H 6950 7450 50  0001 C CNN "Price"
	2    6950 7450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 61093AE9
P 8150 4000
F 0 "C9" H 8100 3850 50  0000 L CNN
F 1 "10u" V 8200 4050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8150 4000 50  0001 C CNN
F 3 "~" H 8150 4000 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A106MQ8NNNC" H 8150 4000 50  0001 C CNN "Link"
F 5 "0.01596" H 8150 4000 50  0001 C CNN "Price"
	1    8150 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C16
U 1 1 61095278
P 11400 4800
F 0 "C16" H 11350 4850 50  0000 L CNN
F 1 "1u" H 11350 4750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 11400 4800 50  0001 C CNN
F 3 "~" H 11400 4800 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A105KP8NNNC" H 11400 4800 50  0001 C CNN "Link"
F 5 "0.00742" H 11400 4800 50  0001 C CNN "Price"
	1    11400 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C17
U 1 1 6109558E
P 11400 5350
F 0 "C17" H 11350 5400 50  0000 L CNN
F 1 "1u" H 11350 5300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 11400 5350 50  0001 C CNN
F 3 "~" H 11400 5350 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10A105KP8NNNC" H 11400 5350 50  0001 C CNN "Link"
F 5 "0.00742" H 11400 5350 50  0001 C CNN "Price"
	1    11400 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R12
U 1 1 61095F4F
P 7450 7450
F 0 "R12" V 7350 7550 50  0000 C CNN
F 1 "18R" V 7350 7300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7450 7450 50  0001 C CNN
F 3 "~" H 7450 7450 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 7450 7450 50  0001 C CNN "Link"
F 5 "0.00196" H 7450 7450 50  0001 C CNN "Price"
	1    7450 7450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R9
U 1 1 6109817D
P 6400 7150
F 0 "R9" H 6500 7200 50  0000 C CNN
F 1 "12k" H 6500 7100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6400 7150 50  0001 C CNN
F 3 "~" H 6400 7150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 6400 7150 50  0001 C CNN "Link"
F 5 "0.0019" H 6400 7150 50  0001 C CNN "Price"
	1    6400 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R10
U 1 1 610987B9
P 6400 7650
F 0 "R10" H 6500 7700 50  0000 C CNN
F 1 "12k" H 6500 7600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6400 7650 50  0001 C CNN
F 3 "~" H 6400 7650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 6400 7650 50  0001 C CNN "Link"
F 5 "0.0019" H 6400 7650 50  0001 C CNN "Price"
	1    6400 7650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R15
U 1 1 61099706
P 8500 7650
F 0 "R15" H 8400 7650 50  0000 L CNN
F 1 "1k" H 8350 7750 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8500 7650 50  0001 C CNN
F 3 "~" H 8500 7650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 8500 7650 50  0001 C CNN "Link"
F 5 "0.00196" H 8500 7650 50  0001 C CNN "Price"
	1    8500 7650
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R13
U 1 1 61099AC5
P 8450 8400
F 0 "R13" H 8350 8400 50  0000 L CNN
F 1 "1k" H 8300 8500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8450 8400 50  0001 C CNN
F 3 "~" H 8450 8400 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 8450 8400 50  0001 C CNN "Link"
F 5 "0.00196" H 8450 8400 50  0001 C CNN "Price"
	1    8450 8400
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R18
U 1 1 6109A107
P 9000 7650
F 0 "R18" H 9100 7700 50  0000 C CNN
F 1 "12k" H 9100 7600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9000 7650 50  0001 C CNN
F 3 "~" H 9000 7650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 9000 7650 50  0001 C CNN "Link"
F 5 "0.0019" H 9000 7650 50  0001 C CNN "Price"
	1    9000 7650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R16
U 1 1 6109A906
P 8950 8400
F 0 "R16" H 9050 8450 50  0000 C CNN
F 1 "12k" H 9050 8350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8950 8400 50  0001 C CNN
F 3 "~" H 8950 8400 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 8950 8400 50  0001 C CNN "Link"
F 5 "0.0019" H 8950 8400 50  0001 C CNN "Price"
	1    8950 8400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C3
U 1 1 6109BE79
P 4900 2800
F 0 "C3" H 5000 2800 50  0000 C CNN
F 1 "100n" H 5000 2900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4900 2800 50  0001 C CNN
F 3 "~" H 4900 2800 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 4900 2800 50  0001 C CNN "Link"
F 5 "0.00499" H 4900 2800 50  0001 C CNN "Price"
	1    4900 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R22
U 1 1 6109E496
P 10850 4650
F 0 "R22" H 10750 4650 50  0000 L CNN
F 1 "1k" H 10700 4750 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 10850 4650 50  0001 C CNN
F 3 "~" H 10850 4650 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 10850 4650 50  0001 C CNN "Link"
F 5 "0.00196" H 10850 4650 50  0001 C CNN "Price"
	1    10850 4650
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R23
U 1 1 6109ECED
P 10850 5200
F 0 "R23" H 10750 5200 50  0000 L CNN
F 1 "1k" H 10700 5300 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 10850 5200 50  0001 C CNN
F 3 "~" H 10850 5200 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 10850 5200 50  0001 C CNN "Link"
F 5 "0.00196" H 10850 5200 50  0001 C CNN "Price"
	1    10850 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R17
U 1 1 6109ACFA
P 8950 9150
F 0 "R17" H 9050 9200 50  0000 C CNN
F 1 "12k" H 9050 9100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8950 9150 50  0001 C CNN
F 3 "~" H 8950 9150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 8950 9150 50  0001 C CNN "Link"
F 5 "0.0019" H 8950 9150 50  0001 C CNN "Price"
	1    8950 9150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R14
U 1 1 61099DDE
P 8450 9150
F 0 "R14" H 8350 9150 50  0000 L CNN
F 1 "1k" H 8300 9250 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8450 9150 50  0001 C CNN
F 3 "~" H 8450 9150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 8450 9150 50  0001 C CNN "Link"
F 5 "0.00196" H 8450 9150 50  0001 C CNN "Price"
	1    8450 9150
	0    1    1    0   
$EndComp
$Comp
L Device:Opamp_Quad_Generic U3
U 3 1 60F6C53B
P 9000 7350
F 0 "U3" H 9000 7550 50  0000 C CNN
F 1 "TLV9064IDR" H 9000 7650 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 9000 7350 50  0001 C CNN
F 3 "~" H 9000 7350 50  0001 C CNN
F 4 "https://ozdisan.com/entegre-devreler-ics/lineer-entegreler/amplifikatorler/TLV9064IDR" H 9000 7350 50  0001 C CNN "Link"
F 5 "0.77646" H 9000 7350 50  0001 C CNN "Price"
	3    9000 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C12
U 1 1 60F3A059
P 9600 9000
F 0 "C12" H 9692 9046 50  0000 L CNN
F 1 "100n" H 9692 8955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9600 9000 50  0001 C CNN
F 3 "~" H 9600 9000 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/kondansatorler/smt-smd-ve-mlcc-kondansatorler/CL10B104KB8NNND" H 9600 9000 50  0001 C CNN "Link"
F 5 "0.00499" H 9600 9000 50  0001 C CNN "Price"
	1    9600 9000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R20
U 1 1 60F38FDA
P 9450 8850
F 0 "R20" V 9350 8950 50  0000 C CNN
F 1 "18R" V 9350 8800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9450 8850 50  0001 C CNN
F 3 "~" H 9450 8850 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 9450 8850 50  0001 C CNN "Link"
F 5 "0.00196" H 9450 8850 50  0001 C CNN "Price"
	1    9450 8850
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 9150 8300 9150
Text Label 8300 9150 2    50   ~ 0
VGND
Wire Wire Line
	9600 8850 9700 8850
Text Label 9700 8850 0    50   ~ 0
CHA_C
Wire Wire Line
	9600 9150 9600 9100
Wire Wire Line
	9600 8850 9600 8900
Connection ~ 9600 8850
Wire Wire Line
	9550 8850 9600 8850
$Comp
L power:GND #PWR022
U 1 1 611109B1
P 9600 9150
F 0 "#PWR022" H 9600 8900 50  0001 C CNN
F 1 "GND" H 9700 9150 50  0000 C CNN
F 2 "" H 9600 9150 50  0001 C CNN
F 3 "" H 9600 9150 50  0001 C CNN
	1    9600 9150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 8750 8500 8750
Text Label 8500 8750 2    50   ~ 0
SIGNAL_C
Wire Wire Line
	8550 9150 8600 9150
Wire Wire Line
	8850 9150 8600 9150
Connection ~ 8600 9150
Wire Wire Line
	8600 8950 8600 9150
Wire Wire Line
	8650 8950 8600 8950
Wire Wire Line
	9300 8850 9350 8850
Wire Wire Line
	9300 8850 9250 8850
Connection ~ 9300 8850
Wire Wire Line
	9300 9150 9300 8850
Wire Wire Line
	9050 9150 9300 9150
$Comp
L Device:R_Small R5
U 1 1 61096B5F
P 4100 5450
F 0 "R5" V 4000 5550 50  0000 C CNN
F 1 "18R" V 4000 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4100 5450 50  0001 C CNN
F 3 "~" H 4100 5450 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 4100 5450 50  0001 C CNN "Link"
F 5 "0.00196" H 4100 5450 50  0001 C CNN "Price"
	1    4100 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R4
U 1 1 610967E0
P 4100 5150
F 0 "R4" V 4000 5250 50  0000 C CNN
F 1 "18R" V 4000 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4100 5150 50  0001 C CNN
F 3 "~" H 4100 5150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF180JT5E" H 4100 5150 50  0001 C CNN "Link"
F 5 "0.00196" H 4100 5150 50  0001 C CNN "Price"
	1    4100 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 5450 4200 5450
Wire Wire Line
	4200 5150 4250 5150
Text Label 5100 5150 0    50   ~ 0
PULSE
$Comp
L oe_flow:SN74LVC2G17 U1
U 1 1 60F2A331
P 4500 5150
F 0 "U1" H 4500 5000 50  0000 C CNN
F 1 "SN74LVC2G17" H 4500 5050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 4500 5150 50  0001 C CNN
F 3 "~" H 4500 5150 50  0001 C CNN
F 4 "https://ozdisan.com/Product/Detail/461876/SN74LVC2G17DBVR" H 4500 5150 50  0001 C CNN "Link"
F 5 "0.25423" H 4500 5150 50  0001 C CNN "Price"
	1    4500 5150
	-1   0    0    1   
$EndComp
Text Label 5100 5450 0    50   ~ 0
PULSE_N
$Comp
L Device:R_Small R6
U 1 1 60FB7E74
P 4850 5000
F 0 "R6" H 4750 5000 50  0000 L CNN
F 1 "1k" H 4700 5100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4850 5000 50  0001 C CNN
F 3 "~" H 4850 5000 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 4850 5000 50  0001 C CNN "Link"
F 5 "0.00196" H 4850 5000 50  0001 C CNN "Price"
	1    4850 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R7
U 1 1 60FB88E8
P 4950 5000
F 0 "R7" H 5000 5000 50  0000 L CNN
F 1 "1k" H 4950 5100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4950 5000 50  0001 C CNN
F 3 "~" H 4950 5000 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1001T5E" H 4950 5000 50  0001 C CNN "Link"
F 5 "0.00196" H 4950 5000 50  0001 C CNN "Price"
	1    4950 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 5100 4850 5150
Wire Wire Line
	4850 5150 4800 5150
Wire Wire Line
	5100 5150 4850 5150
Connection ~ 4850 5150
Wire Wire Line
	4800 5450 4950 5450
Wire Wire Line
	4950 5100 4950 5450
Connection ~ 4950 5450
Wire Wire Line
	4950 5450 5100 5450
$Comp
L power:+5V #PWR06
U 1 1 60FE2C58
P 4900 4800
F 0 "#PWR06" H 4900 4650 50  0001 C CNN
F 1 "+5V" H 4915 4973 50  0000 C CNN
F 2 "" H 4900 4800 50  0001 C CNN
F 3 "" H 4900 4800 50  0001 C CNN
	1    4900 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4800 4900 4850
Wire Wire Line
	4900 4850 4850 4850
Wire Wire Line
	4850 4850 4850 4900
Wire Wire Line
	4900 4850 4950 4850
Wire Wire Line
	4950 4850 4950 4900
Connection ~ 4900 4850
$Comp
L oe_flow:SN74LVC2G17 U1
U 2 1 60FF5B95
P 4500 5450
F 0 "U1" H 4500 5300 50  0000 C CNN
F 1 "SN74LVC2G17" H 4500 5350 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 4500 5450 50  0001 C CNN
F 3 "~" H 4500 5450 50  0001 C CNN
F 4 "https://ozdisan.com/Product/Detail/461876/SN74LVC2G17DBVR" H 4500 5450 50  0001 C CNN "Link"
F 5 "0.25423" H 4500 5450 50  0001 C CNN "Price"
	2    4500 5450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 5850 4200 5850
Text Label 4200 5850 0    50   ~ 0
SIGNAL_C
Wire Wire Line
	4000 6450 4200 6450
Connection ~ 4000 6450
Wire Wire Line
	3950 6450 4000 6450
Wire Wire Line
	3950 6500 3950 6450
Wire Wire Line
	3900 6500 3950 6500
Wire Wire Line
	4000 6650 4200 6650
Connection ~ 4000 6650
Wire Wire Line
	3950 6650 4000 6650
Wire Wire Line
	3950 6600 3950 6650
Wire Wire Line
	3900 6600 3950 6600
Wire Wire Line
	4000 7250 4200 7250
Connection ~ 4000 7250
Wire Wire Line
	3950 7250 4000 7250
Wire Wire Line
	3950 7200 3950 7250
Wire Wire Line
	3900 7200 3950 7200
Wire Wire Line
	4000 7050 4200 7050
Connection ~ 4000 7050
Wire Wire Line
	3950 7050 4000 7050
Wire Wire Line
	3950 7100 3950 7050
Wire Wire Line
	3900 7100 3950 7100
$Comp
L Device:R_Small R3
U 1 1 61005C53
P 4000 7150
F 0 "R3" H 4100 7200 50  0000 C CNN
F 1 "12k" H 4100 7100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4000 7150 50  0001 C CNN
F 3 "~" H 4000 7150 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 4000 7150 50  0001 C CNN "Link"
F 5 "0.0019" H 4000 7150 50  0001 C CNN "Price"
	1    4000 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 61005923
P 4000 6550
F 0 "R2" H 4100 6600 50  0000 C CNN
F 1 "12k" H 4100 6500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4000 6550 50  0001 C CNN
F 3 "~" H 4000 6550 50  0001 C CNN
F 4 "https://ozdisan.com/pasif-komponentler/direncler/smt-smd-ve-cip-direncler/0603SAF1202T5E" H 4000 6550 50  0001 C CNN "Link"
F 5 "0.0019" H 4000 6550 50  0001 C CNN "Price"
	1    4000 6550
	1    0    0    -1  
$EndComp
Text Label 4200 7250 0    50   ~ 0
VGND
$Comp
L Device:Speaker_Ultrasound LS4
U 1 1 6147DD8F
P 3700 7200
F 0 "LS4" H 4000 6950 50  0000 C CNN
F 1 "Speaker_Ultrasound" H 4000 6850 50  0000 C CNN
F 2 "oe_ultrasonic:GU1007C-40TR" H 3665 7150 50  0001 C CNN
F 3 "~" H 3665 7150 50  0001 C CNN
F 4 "1.27" H 3700 7200 50  0001 C CNN "Price"
F 5 "https://lcsc.com/product-detail/_INGHAi-GU1007C-40TR_C242175.html" H 3700 7200 50  0001 C CNN "Link"
	1    3700 7200
	-1   0    0    1   
$EndComp
Text Label 4200 7050 0    50   ~ 0
SIGNAL_B
Text Label 4200 6650 0    50   ~ 0
VGND
$Comp
L Device:Speaker_Ultrasound LS3
U 1 1 61470BB2
P 3700 6600
F 0 "LS3" H 4000 6350 50  0000 C CNN
F 1 "Speaker_Ultrasound" H 4000 6250 50  0000 C CNN
F 2 "oe_ultrasonic:GU1007C-40TR" H 3665 6550 50  0001 C CNN
F 3 "~" H 3665 6550 50  0001 C CNN
F 4 "1.27" H 3700 6600 50  0001 C CNN "Price"
F 5 "https://lcsc.com/product-detail/_INGHAi-GU1007C-40TR_C242175.html" H 3700 6600 50  0001 C CNN "Link"
	1    3700 6600
	-1   0    0    1   
$EndComp
Text Label 4200 6450 0    50   ~ 0
SIGNAL_A
$EndSCHEMATC
