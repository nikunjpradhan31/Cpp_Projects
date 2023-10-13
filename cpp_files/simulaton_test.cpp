// Programmer: Nikunj Pradhan
// Date: 10/11/2023
// File: hw4.cpp
// Assignment: HW4
// Purpose: this file is keeping Jamie calm at the dentists
#include<iostream>
using namespace std;

int main()
{
  int anxiety;
  bool pass_check; //this variable checks if Jamie is calm enough to do the procedure.
  bool activity = false; //checks if Jamie has done an activity
  bool remember_show = false; // this variable checks if Jamie
  bool leave = false;
  bool operation = false;
  float totalbill = 0;
  char choice, choice_act,choice_speak,choice_enter,choice_exit, choice_procedure;
  string billine = "";
  do{//anixety do while
    cout<<"\nEnter Jamie's intial anxiety level(0-10): ";
    cin>>anxiety;
  }while(anxiety < 0 || anxiety > 10);//anixety do while

do{//full simulaton do while
  do{//main menu actions //do while that prevents the user from entering an incorrect answer
    cout<<"\n1. Choose a waiting room activity\n2. Speak with the receptionist \n3. Enter the dentist's room\n4. Consider leaving\nEnter your choice: ";
    cin>>choice;
  }while(choice != '1' &&  choice != '2' &&  choice != '3' &&  choice != '4');//main menu actions

  switch(choice)
  {//switch choice

    case '1':
      do{//choice_act menu
        cout<<"\n1. Read a comic book\n2. Play a handheld video game\n3. Watch a cartoon on TV\n4. Doodle on a piece of paper\n5. Do nothing\nEnter a choice: ";
        cin>>choice_act;
        }while(choice_act != '1' &&  choice_act != '2' &&  choice_act != '3' &&  choice_act != '4' && choice_act != '5');//choice_act menu


      switch(choice_act){//switch_act
        case '1':
        (anxiety -2 >= 0) ? cout<< "\nJamie reads a comic book"<<endl : cout <<"\nJamie is already calm. Please try another option." << endl;
	(anxiety -2 >= 0) ? (anxiety -= 2) : anxiety;
        activity = true;
         break;
        case '2':
         if(anxiety-3 >= 0){//handles edge cases and adds the totalbill if Jamie is not calm enough
          anxiety -= 3;
          totalbill += 50;
          billine += "\nHandheld video game : $50.00";
          activity = true;
          cout<<"\nJamie plays a video game."<<endl;}
	 else
          cout<<"\nJamie is already calm. Please try another option."<<endl;
         break;
        case '3':
         if(anxiety -2 >=0){
          anxiety -= 2;
          cout<<"\nJamie watches a cartoon."<<endl;
          activity = true;
          remember_show = true;}
         else
          cout<<"\nJamie is already calm. Please try another option."<<endl;
         break;
        case '4':
         if(anxiety+1<=10){
          totalbill +=20;
          cout<<"\nJamie doodles on a piece a paper, but had to pay for it."<<endl;
          activity = true;
          billine += "\nDoodle on a piece of paper : $20.00";
          anxiety +=1;}
         else
          cout<<"\nJamie is already too stressed. Please try another option."<<endl;
         break;
        case '5':
         if(anxiety+1<=10){
          totalbill += 7.20;
          cout<<"\nJamie sits and does nothing, he becomes more stressed."<<endl;
          billine += "\nComfort fee : $7.20";
          anxiety += 1;}
         else
          cout<<"\nJamie is already too stressed. Please try another option."<<endl;
         break;
      }//switch_act
   break;

  case '2':
   do{//choice_speak  menu
    cout<<"\n1. What will the dentist do?\n2. How long will it take?\n3. Can I have candy after?\nEnter a choice: ";
    cin>>choice_speak;
   }while(choice_speak != '1' &&  choice_speak != '2' &&  choice_speak != '3');//choice_act menu

   switch(choice_speak){//choice_speak_switch
    case '1':
     (anxiety + 1 <= 10) ? cout<<"\nThe receptionist explains the standard procedures."<<endl : cout<<"\nJamie is too stressed. Please select another option."<<endl;
     (anxiety + 1 <= 10) ? (anxiety += 1) : anxiety;//double ternary statement that checks the edge cases if it goes over 10
     break;
    case '2':
     if(anxiety - 1>=0){
      anxiety -= 1;
      cout<<"\nJamie is informed that operation will be about 30 minutes."<<endl;}
     else
      cout<<"\nJamie is already calm. Please choose another option."<<endl;
     break;
    case '3':
     int candy;
     do{//candy_do_while
       cout<<"\nHow many pieces of candy would you like (0-5): ";
       cin>>candy;
       }while(candy <  0 || candy > 5);//candy_do_while
       if(candy <= 2){//this is the case when the amount of candies wanted is less than or equal to 2
        if(anxiety -2 >= 0){
           cout<<"\nJamie is offered "<<candy<<" pieces of candy"<<endl;
           string candy_string = to_string(candy*10);
           billine += "\nCandy pieces : $" + candy_string;
           anxiety -= 2;}
        else{
            cout<<"\nJamie is already calm. Please select another option."<<endl;
            candy = 0;
            break;
            }
       }
       else{//else
      if(anxiety -4 >= 0){//if //this is the case when the amount of candies wanted is greater than 2 and his anxiety is greater than or equal to 4
           cout<<"\nJamie is offered "<<candy<<" pieces of candy"<<endl;
           string candy_string = to_string(candy*10);
           billine += "\nCandy pieces : $" + candy_string;
           anxiety -= 4;}//if
        else{//else
            cout<<"\nJamie is already calm. Please select another option."<<endl;
            candy = 0;
            break;
            }//else
      totalbill += candy*10;
        }//else
    break;
   }//choice_speak_switch
   break;

  case '3':
   do{//choice_enter do while
     cout<<"\n1. Speak with the dentist\n2. Choose a toy to hold during the visit\n3. Start the dental procedure\nEnter your choice: ";
     cin>>choice_enter;
      if(anxiety - 1 >= 0)//statement that happens when Jamie enters the room
        anxiety-=1;
      if(activity == false && anxiety <= 5 && anxiety >= 1)
        anxiety += 1;
     switch(choice_enter){//switch choice_enter
      case '1':
       if (anxiety -2 >= 0){
        cout<<"\nJamie and the dentist engage in a light conversation."<<endl;
        anxiety -= 2;
        billine += "\nSpeaking with Dentist : $40.00";
        totalbill +=40;}
      else{
        cout<<"\nJamie is calm enough."<<endl;
        if(anxiety < 5)
          pass_check = true;}//pass_check allows Jamie to directly do a dentist operation if he did one of the preconditions
      break;

     case '2':
      if(anxiety - 3 >= 0){
        cout<<"\nJamie has bought a soft plush toy."<<endl;
        anxiety -= 3;
        billine += "\nSoft Plush Toy : $32.00";
        totalbill+=32;}
     else{
        cout<<"\nJamie is calm enough without the plush toy."<<endl;
        if(anxiety < 5)
          pass_check = true;}
     break;

     case '3':
       do{//choice_procedure do while
         cout<<"\n1. Standard Checkup\n2.Teeth Cleaning\n3. Cavity filling\n4.Specialist consultation\nEnter your choice: ";
         cin>>choice_procedure;
       }while(choice_procedure != '1' &&choice_procedure != '2' &&choice_procedure != '3' &&choice_procedure != '4');//choice_procedure do while

       operation = true;//if this boolean is true then the do while / switch cases will terminate, the simulation will end

       switch(choice_procedure){//switch choice_procedure
         case '1':
           anxiety += 1;
           totalbill += 50;
           billine += "\nStandard Checkup : $50.00";
           break;
         case '2':
           anxiety += 2;
           billine += "\nTeeth Cleaning : $75.00";
           totalbill += 75;
           break;
         case '3':
           anxiety += 3;
           billine += "\nCavity Filling : $100.00";
           totalbill += 100;
           break;
         case '4':
           anxiety +=2;
           billine += "\nSpecialist Consultation : $300.00";
           totalbill += 300;
           break;
      }//choice_procedure switch
    }//switch choice_enter
      if(pass_check == true){//passcheck //this is the same function as doing an operation, however this one automatically has Jamie enter the room if he is calm enough
       do{//choice_procedure do while
         cout<<"\n1. Standard Checkup\n2.Teeth Cleaning\n3. Cavity filling\n4.Specialist consultation\nEnter your choice: ";
         cin>>choice_procedure;
       }while(choice_procedure != '1' &&choice_procedure != '2' &&choice_procedure != '3' &&choice_procedure != '4');//choice_procedure do while

       operation = true;

       switch(choice_procedure){//switch choice_procedure
         case '1':
           anxiety += 1;
           billine += "\nStandard Checkup : $50.00";

           totalbill += 50;
           break;
         case '2':
           anxiety += 2;
           billine += "\nTeeth Cleaning : $75.00";
           totalbill += 75;
           break;
         case '3':
           anxiety += 3;
           billine += "\nCavity Filling : $100.00";
           totalbill += 100;
           break;
         case '4':
           anxiety +=2;
           billine += "\nSpecialist Consultation : $300.00";
           totalbill += 300;
           break;
      }//choice_procedure switch
     }//if pass_check
   }while(choice_enter != '1' && choice_enter != '2' && choice_enter != '3');//choice_enter do while loop
   break;

  case '4':
   if(anxiety -4 >= 0){
      anxiety -= 4;
      leave = true;//the do while and switch cases will terminate and this will be the last time it will run/
      totalbill+= 250;
      billine += "\nMissed Appointment Fee : $250.00";
      cout<<"\nJamie has left the dentists."<<endl;}
  else
      cout<<"\nJamie is calm enough and does need to leave the office"<<endl;
   break;
  }//switch_choice

}while(leave == false && operation == false);//full simulation do while //if Jamie did not leave nor did he have an operation then the do while will run again.
cout<<"\nBilling Details:\n---------------"<<billine<<"\n---------------\nTotal Amount Due: $"<<totalbill<<"\n\nJamie's Anxiety Level: "<<anxiety<<endl;
return 0;
}//main
