/*
 ===================================================================================================
 Name        : Mohamed Adel Amin
 Description : Vehicle Control System project.
 ===================================================================================================
 */
#include<stdio.h>

#define ON 1
#define OFF 0
#define ENGINE_TEMP_CONTROLLER 1

void Sensors_set_menu(void);
void Traffic_light(void);
void Temperature_sensor(void);
void Engine_temperature_sensor(void);
void display_State(void);

struct vehicle_control_system
{
	int Vehicle_Speed ,Room_Temperature,Engine_Temperature;
	int AC_State ,Engine_Controller_state;

};

struct vehicle_control_system car={20,25,80,OFF,OFF};
struct vehicle_control_system *car_ptr=&car;

int main(void)
{
	char operation1;
	printf("\t\t!!!Vehicle Control System!!!\n\n");
	printf("a-Turn on the vehicle engine\n");
	printf("b-Turn off the vehicle engine\n");
	printf("c-Quit the system\n");
	printf("--Select an operation--\n");
	fflush(stdout);

	scanf(" %c",&operation1);
	switch(operation1)
	{
	case'a':
		    printf("\t\tTurn on the vehicle engine\n\n");
		    Sensors_set_menu();
		    break;
	case'b':
		    printf("\t\tTurn off the vehicle engine\n\n");
		    main();
			break;
	case'c':
		    printf("\t\tQuit program\n\n");
			return 0;
			break;
	default:
			printf("\t\tInvalid operation\n\n");
	        break;

	}
	return 0;
}
void Sensors_set_menu(void){

	char operation2;

	printf("a-Turn off the engine\n");
	printf("b-Set the traffic light color\n");
	printf("c-Set the room temperature (Temperature Sensor)\n");
#if(ENGINE_TEMP_CONTROLLER)
	printf("d-Set the engine temperature (Engine Temperature Sensor)\n");
#endif
	printf("--Select an operation--\n");
	fflush(stdout);

	scanf(" %c",&operation2);

	switch(operation2)
	{
	case'a':
		printf("\t\tEngine is turned OFF\n\n");
		main();
	    break;
	case'b':
	    Traffic_light();
	    display_State();
		Sensors_set_menu();
		break;
	case'c':
		Temperature_sensor();
		display_State();
		Sensors_set_menu();
		break;
#if(ENGINE_TEMP_CONTROLLER)
	case'd':
		Engine_temperature_sensor();
		display_State();
		Sensors_set_menu();
		break;
#endif
	default :
		printf("\tInvalid operation\n\n");
		Sensors_set_menu();
		break;
	}

}

void Traffic_light(void)
{
	char operation3;

	printf("\t\tSet the traffic light color\n");
	printf("!!select g-o-r!!\n");

	fflush(stdout);

	scanf(" %c",&operation3);

	switch(operation3)
	{
	case'g':
		car_ptr->Vehicle_Speed=100;
		break;
	case'o':
		car_ptr->Vehicle_Speed=30;
		break;
	case'r':
		car_ptr->Vehicle_Speed=0;
		break;
	default :
		printf("\tInvalid operation\n\n");
		Traffic_light();
		break;
	}
}
void Temperature_sensor(void)
{
	printf("\t\tSet room temperature\n\n");
	fflush(stdout);

	scanf("%d",&car.Room_Temperature);

	if(car_ptr->Room_Temperature<10)
	{
		car_ptr->AC_State=ON;
		car_ptr->Room_Temperature=20;
	}
	else if(car_ptr->Room_Temperature>30)
	{
		car_ptr->AC_State=ON;
		car_ptr->Room_Temperature=20;
	}
	else
	{
		car_ptr->AC_State=OFF;
	}

}
void Engine_temperature_sensor(void)
{

	printf("\t\tSet Engine temperature\n\n");
	fflush(stdout);

	scanf("%d",&car.Engine_Temperature);

	if(car_ptr->Engine_Temperature<100)
	{
		car_ptr->Engine_Controller_state=ON;
		car_ptr->Engine_Temperature=125;
	}
	else if(car_ptr->Engine_Temperature>150)
	{
		car_ptr->Engine_Controller_state=ON;
		car_ptr->Engine_Temperature=125;
	}
	else
	{
		car_ptr->Engine_Controller_state=OFF;
	}

}
void display_State(void)
{
	if(car_ptr->Vehicle_Speed==30)
	{
		car_ptr->AC_State=ON;
		car_ptr->Room_Temperature=car_ptr->Room_Temperature*(5/4)+1;
#if(ENGINE_TEMP_CONTROLLER)
		car_ptr->Engine_Controller_state=ON;
		car_ptr->Engine_Temperature=car_ptr->Engine_Temperature*(5/4)+1;
#endif
	}
	printf("-Engine is ON\n");
	if(car_ptr->AC_State)
	{
		printf("-AC State is ON\n");
	}
	else
	{
		printf("-AC State is OFF\n");

	}
	printf("-Vehicle Speed:%d Km/h\n",(*car_ptr).Vehicle_Speed);
	printf("-Room Temperature:%d\n",(*car_ptr).Room_Temperature);
#if(ENGINE_TEMP_CONTROLLER)
	if(car_ptr->Engine_Controller_state)
	{
		printf("-Engine Controller is ON\n");
	}
	else
	{
		printf("-Engine Controller is OFF\n");

	}
	printf("-Engine Temperature:%d\n\n",(*car_ptr).Engine_Temperature);
#endif
}
