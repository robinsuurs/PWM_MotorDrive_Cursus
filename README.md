# PWM_MotorDrive_Cursus

## Timer check list

### 1. Welke timer gerbruik je? 
Dit hangt af van hoe naukeurig je moet zijn. Is 8-bits voldoende? Neem Timer 0 of 2. Heb je meer naukeurigheid nodig? Neem Timer 1. 

### 2. Welke modus wil je gebruiken? 
Zie tabel "Waveform Generation Mode Bit Description" in de data sheet en zet de WGMn bits goed. 

### 3. Wil je een directe output geven?
Zet de COMnx bits goed in TCCRnA

>Vergeet de bijhoorende pinnen in het DDR als output te zetten.

### 4. kies de snelheid die je wil
Door de CSnx bits te zetten in TCCRnB

### 5. gebruik je een compare waarde?
Dan is het handig om een defult waarde vast in het compare register te zetten. 

