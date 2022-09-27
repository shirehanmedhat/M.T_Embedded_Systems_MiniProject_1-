/*
 ============================================================================
 Name        : Mini_Project_Final.c
 Author      : Shirehan Medhat Abdelsalam Ali
 Description : Vehicle Control System Project.
 Date        : 23/8/2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mini_Project.h"
int main(void) {
	// Create a variable from DATA type to store all the states
	Data INPUT_DATA ={
			OFF_Engine,
			OFF_AC,
			DefaultVehicleSpeed,
			DefaultRoomTemperature,
			OFF_Temperature_Controller,
			DefaultEngineTemperature};
	// Create a pointer from DATA type to store the INPUT_DATA variable adress
	Data *PTR_TO_INPUT_DATA = &INPUT_DATA;

	// Super Loop o Display the Introduction list.
	while (1)
	{
        // Display Introduction list and ask the user to choose a Choice
		char Choice = Intoduction ();
		//Print the Choice which the user has chose.
		printf("The choice is %c\n",Choice);
		fflush(stdout);
		//Quite the system and break the super loop incase : c
		if ('c'==Choice)
		{
			printf("Quit the system\n");
			break;
		}
		// reloop the super loop again and Display Introduction list incse  :b
		else if ('b'==Choice)
		{
			continue;
		}
		// Incse : a
		while ('a' == Choice)
		{
			//Turn the Engine ON
			PTR_TO_INPUT_DATA->EngineCase = ON_Engine;
			char SensorChoice;
			//Display the Sensor List Menu
			SensorSetMenu (&SensorChoice);


			//INCASE : a
			/* break the internal loop which means
			back to the super loop and Display the Introduction list again*/
			if ('a'==SensorChoice)
			{
				break;
			}
			//INCASE : b
			else if ('b'==SensorChoice)
			{
				// ask the user to enter the color
				char Color;
				printf("Enter the required color\n");
				fflush(stdout);
				scanf(" %c",&Color);
				//Set the Speed depending on the color
				TrafficLightSpeed (Color , PTR_TO_INPUT_DATA);
				//Display the state
				PrintResult (PTR_TO_INPUT_DATA);
				//to display the the Sensor List Menu again
				continue;
			}
			//INCASE : c
			else if ('c'==SensorChoice)
			{
				// ask the user to enter the temp
				int RoomTemp;
				printf("Enter the required room temp:\n");
				fflush(stdout);
				scanf("%d",&RoomTemp);
				// Set the room temp depending on the input
				SetRoomTemp (&RoomTemp , PTR_TO_INPUT_DATA);
				//Display the state
				PrintResult (PTR_TO_INPUT_DATA);
				//to display the the Sensor List Menu again
				continue;
			}
			//INCASE : d
			else if ('d'== SensorChoice)
			{
				// ask the user to enter the engine temp
                #if CASE == ON
				int EngineTemp;
				printf("Enter the required engine temp:\n");
				fflush(stdout);
				scanf("%d",&EngineTemp);
				// Set the engine temp depending on the input
				SetEngineTempController (&EngineTemp, PTR_TO_INPUT_DATA);
				PrintResult (PTR_TO_INPUT_DATA);
				//to display the the Sensor List Menu again
				continue;
                #endif
			}

		}
	}
	return 0;
}
