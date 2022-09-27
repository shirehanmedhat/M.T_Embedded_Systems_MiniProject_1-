/*
 ============================================================================
 Name        : Mini_Project_Func.c
 Author      : Shirehan Medhat Abdelsalam Ali
 Description : Vehicle Control System Project.
 Date        : 23/8/2022
 ============================================================================
 */

// Body Of Functions
#include <stdio.h>
#include"Mini_Project.h"
//--------------------------------------------------------------------------------
// Function to ask the user what he/she wants at the beginning of the program
//the function Return char with the chosen choice
char Intoduction (void)
{
	char input ;
	printf("a. Turn on the vehicle engine\n");
	fflush(stdout);
	printf("b. Turn off the vehicle engine\n");
	fflush(stdout);
	printf("c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c",&input);
	return input;

}
//---------------------------------------------------------------------------------
//Function to represent the Sensor Set menu in case the Engine is ON
// This function returns NOTHING because it takes a pointer to character from the main and update it
//"pass by adress"
void SensorSetMenu (char *PtrToSensorChoice)
{
	if (PtrToSensorChoice != NULL)
	{
		printf("\na. Turn off the engine\n");
		fflush(stdout);
		printf("b. Set the traffic light color\n");
		fflush(stdout);
		printf("c. Set the room temperature\n");
		fflush(stdout);
		/*Using the directives To control the appearance of the Engine Temp Choice
	 depending on the CASE Value (OFF-ON)*/
        #if CASE == ON
		printf("d. Set the engine temperature\n");
		fflush(stdout);
        #endif
		scanf(" %c",PtrToSensorChoice);
	}
}
//----------------------------------------------------------------------------------
//Function to choose the speed depending on the chosen color
//this function return void and has two input arguments
//1- the input color taken form user
//2- pointer to struct to update the struct elements by adress
void TrafficLightSpeed (char InputColor , Data *PtrToInputData)
{
	if (PtrToInputData != NULL)
	{
		switch (InputColor)
		{
		case'g':
		case'G':
			PtrToInputData->VehicleSpeed =100;
			break;
		case 'o':
		case 'O':
			PtrToInputData->VehicleSpeed= 30;
			PtrToInputData->AC_Case = ON_AC;
			//INCASE speed ==30 the Room Temp and the Engine Temp will be modified
			// The SetRoomTemp and SetEngineTempController can not modify the Temp till the speed is changed to any other speed.
			PtrToInputData->RoomTemperature = (((PtrToInputData->RoomTemperature)*(1.25))+1);
			PtrToInputData ->EngineTemperatureController = ON_Temperature_Controller;
			PtrToInputData->EngineTemperature = (((PtrToInputData->EngineTemperature)*(1.25))+1);
			break;
		case 'r':
		case 'R':
			PtrToInputData->VehicleSpeed= 0;
			break;
		}
	}
}

//-------------------------------------------------------------------------------------
// Function to set the Room temp
//this function return void and has two input arguments
//1- the input temp taken form user
//2- pointer to struct to update the struct elements by adress
void SetRoomTemp (int *PtrToRoomTemp , Data *PtrToInputData)
{
	if (PtrToInputData !=NULL)
	{
		// to prevent the function modifying the room temp if the speed ==30
		if ((PtrToInputData->VehicleSpeed) !=30.0)
		{
			if (((*PtrToRoomTemp)<10) || ((*PtrToRoomTemp)>30))
			{
				PtrToInputData->AC_Case = ON_AC;
				PtrToInputData->RoomTemperature =20.0;
			}
			else
			{
				PtrToInputData->AC_Case = OFF_AC;
			}
		}
	}
}
//---------------------------------------------------------------------------------------
// Function to set the Engine temp
//this function return void and has two input arguments
//1- the input engine temp taken form user
//2- pointer to struct to update the struct elements by adress

void SetEngineTempController (int *PtrToEngineTemp , Data *PtrToInputData)
{
	if (PtrToInputData != NULL)
	{
		// to prevent the function modifying the engine temp if the speed ==30
		if ((PtrToInputData->VehicleSpeed) !=30.0)
		{
			if(  ( (*PtrToEngineTemp )<100) || ( (*PtrToEngineTemp )>150) )
			{
				PtrToInputData->EngineTemperatureController = ON_Temperature_Controller;
				PtrToInputData->EngineTemperature=125.0;
			}
			else
			{
				PtrToInputData->EngineTemperatureController = OFF_Temperature_Controller;
			}
		}
	}
}

//------------------------------------------------------------------------------------------
//Function to display the current vehicle state after applying all the steps
// It takes pointer to struct to read the value of the struct elements
void PrintResult (Data *PtrToInputData)
{
	if (PtrToInputData != NULL)
	{
		if ((PtrToInputData->EngineCase) == OFF_Engine)
		{
			printf("\nEngine is OFF\n");
			fflush(stdout);
		}
		else
		{
			printf("\nEngine is ON\n");
			fflush(stdout);

		}

		if ((PtrToInputData->AC_Case) == OFF_AC)
		{
			printf("AC is OFF\n");
			fflush(stdout);
		}
		else
		{
			printf("AC is ON\n");
			fflush(stdout);
		}

		printf("Vehicle Speed: %d Km/Hr\n",(PtrToInputData->VehicleSpeed));
		fflush(stdout);
		printf("Room Temperature: %.2f C\n",(PtrToInputData->RoomTemperature));
		/*Using the directives To control the appearance of the Engine Temp Choice
		 depending on the CASE Value (OFF-ON)*/
        #if CASE == ON
		if ((PtrToInputData->EngineTemperatureController) == OFF_Temperature_Controller)
		{
			printf("Engine Temp Controller is OFF\n");
			fflush(stdout);
		}
		else
		{
			printf("Engine Temp Controller is ON\n");
			fflush(stdout);
		}
		printf("Engine Temperature: %.2f C\n",(PtrToInputData->EngineTemperature));
        #endif
	}
}
//---------------------------------------------------------------------------------------
