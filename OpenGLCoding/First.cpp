#include<iostream>

#define INIT_STATE 0
#define MENU_STATE 1
#define CONSOLE_STATE 2
#define LOADING_STATE 3
#define RUN_STATE 4
#define EXIT_STATE 5
int current_game_state = INIT_STATE;
int main(){

    while(current_game_state!=EXIT_STATE){
        switch(current_game_state){
            case INIT_STATE:{
                //AcquireResources();
                //AllocMem();
                // InitGame();
            }
            break;

            case MENU_STATE:
            {
                //PauseGame();
                //DisplayMenu();
            }
            break;


            case CONSOLE_STATE:
            {
                //DisplayConsole();
            }
            break;


            case LOADING_STATE:
            {
                //DoFinalSetup();
                //current_game_state=RUN_STATE;
            }
            break;

            case RUN_STATE:
            {
                //InputHandling();
                //InitPhysics();
                //InitSound();
                //InitGraphicsSystem();
                //InitNetworking();
                //InitAI();
                //etc
            }
            case EXIT_STATE:
            default: break;
        }
    }
}