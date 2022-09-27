/*
 ============================================================================
 Name        : Mini_Project.h
 Author      : Shirehan Medhat Abdelsalam Ali
 Description : Vehicle Control System Project.
 Date        : 23/8/2022
 ============================================================================
 */
#ifndef MINI_PROJECT_H_
#define MINI_PROJECT_H_

//--------------------------------------------------------------------------
//1- Enumerations
//-Enums For the ON & OFF states of Engine , AC and Temp Controller
typedef enum Engine { OFF_Engine, ON_Engine } Engine;
typedef enum AC    { OFF_AC, ON_AC} AC;
typedef enum TemperatureController { OFF_Temperature_Controller ,ON_Temperature_Controller }TemperatureController;

//--------------------------------------------------------------------------
//2-Hashs To Make The Code Readable
//-Hashs For the initial Values of Speed , Room Temp and Engine Temp
#define DefaultVehicleSpeed 60
#define DefaultRoomTemperature 35.0
#define DefaultEngineTemperature 90.0

//---------------------------------------------------------------------------
//- Hashs For The preprocessor directives To Control the Engine Temp Options
#define ON 1
#define OFF 0
//Try to Comment the ON case and uncomment The OFF case to see the Options disappear
#define CASE ON
/*#define CASE OFF*/

//----------------------------------------------------------------------------
//Struct declaration To Make variable To store Multiple Data Types
typedef struct Data{
	                Engine EngineCase;
					AC AC_Case ;
					int VehicleSpeed ;
					float RoomTemperature ;
					TemperatureController EngineTemperatureController;
					float EngineTemperature;
} Data;

//------------------------------------------------------------------------------
// Functions Prototypes To Call In The Main
char Intoduction (void);
void SensorSetMenu (char *PtrToSensorChoice);
void TrafficLightSpeed (char InputColor , Data *PtrToInputData);
void PrintResult (Data *PtrToInputData);
void SetRoomTemp (int *PtrToRoomTemp , Data *PtrToInputData);
void SetEngineTempController (int *PtrToEngineTemp , Data *PtrToInputData);

//-------------------------------------------------------------------------------
#endif /* MINI_PROJECT_H_ */
