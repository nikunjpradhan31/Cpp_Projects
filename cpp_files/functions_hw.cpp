// Programmer: Nikunj Pradhan
// Date: 10/24/2023
// File: hw5.cpp
// Assignment: HW4
// Purpose: This file is keeping Jamie calm at the dentists using functions
#include <iostream>
#include <string>
using namespace std;

const int MIN_ANXIETY = 0;
const int MAX_ANXIETY = 10;

const double VIDEO_GAME_COST = 50.0;
const double DRAWING_KIT_COST = 20.0;
const double COMFORT_CHARGE = 7.2;
const double CANDY_COST = 10.0;
const double DENTIST_CONSULT_COST = 40.0;
const double TOY_COST = 32.0;
const double MISSED_APPOINTMENT_FEE = 250.0;
const double CHECKUP_COST = 50.0;
const double TEETH_CLEANING_COST = 75.0;
const double CAVITY_FILLING_COST = 100.0;
const double SPECIALIST_CONSULT_COST = 300.0;


void performWaitingRoomActivity(int& anxiety, double& bill, int select_activity,int& activity);
void performReceptionistInteraction(int& anxiety, double& bill, int select_activity,int& activity);
void performReceptionistInteraction(int& anxiety, double& bill, int select_activity);
int performDentistRoomAction(int& anxiety, double& bill, int select_activity,int& activity,bool& procedure);
void DentalProcedure(int& anxiety, double& bill, int select_activity,bool& activity);
void updateAnxietyLevel(int& anxietylevel,int anx_change= 0);
void updateCost(double& totalbill, const double billadd);
void displayFinalSummary(double bill, int anxietyLevel, int comicBookCount, int videoGameCount, int cartoonCount, int doodleCount, int relaxationCount, int totalCandyTaken, int dentistConsultCount, int totalToysTaken, int choice, int procedure_type);

int main() {
    int choice, anxietyLevel;
    double bill = 0;
// Waiting room activities count
    int comicBookCount = 0, videoGameCount = 0;
    int cartoonCount = 0, doodleCount= 0, relaxationCount = 0;
    int procedure_type;
// Reception activities
    int totalCandyTaken = 0;
// Dentist's room activities count
    int dentistConsultCount = 0, totalToysTaken = 0;
// Dental procedure selected
    bool standardCheckup = false, teethCleaning = false;
    bool cavityFilling = false, specialistConsultation = false;
    bool procedure = false;
// Begin simulation
    do {
    cout << "Enter initial anxiety level: (0-10)" << endl;
    cin >> anxietyLevel;
    } while (anxietyLevel < MIN_ANXIETY || anxietyLevel > MAX_ANXIETY);
    do {
        do{
        cout << "Please choose an option: (1-4)\n1. Choose a waiting room activity\n2. Speak with the receptionist\n3. Enter the dentist's room\n4. Consider leaving" << endl;
        cin >> choice;
        } while (choice < 1 || choice > 4);
    switch (choice) {
        case 1: { // Jamie chooses a waiting room activity.
        int waitingRoomChoice;
        do{
        cout << "Please choose a waiting room activity (options 1-5):\n1. Read a comic book\n2. Play a handheld video game\n3. Watch a cartoon on TV\n4. Doodle on a piece of paper\n5. Do nothing"<< endl;
        cin >> waitingRoomChoice;
        } while (waitingRoomChoice < 1 || waitingRoomChoice > 5);
        switch (waitingRoomChoice) {
            case 1: // Jamie chooses to read a comic book
                performWaitingRoomActivity(anxietyLevel, bill, waitingRoomChoice, comicBookCount);
                break;
            case 2: // Jamie chooses to play a video game
                performWaitingRoomActivity(anxietyLevel, bill, waitingRoomChoice, videoGameCount);
                break;
            case 3: // Jamie chooses to watch cartoon
                performWaitingRoomActivity(anxietyLevel, bill, waitingRoomChoice, cartoonCount);
                break;
            case 4: // Jamie chooses to doodle
                performWaitingRoomActivity(anxietyLevel, bill, waitingRoomChoice, doodleCount);
                break;
            case 5: // Jamie chooses to zone out
                performWaitingRoomActivity(anxietyLevel, bill, waitingRoomChoice, relaxationCount);
                break;
        }
        break;
        }
        case 2: { // Jamies chooses to speak to the receptionist.
        int receptionistChoice;
        do{
        cout << "What do you want to ask the receptionist?:\n1. What will the dentist do?\n2. How long will it take?\n3. Can I have a candy after?" << endl;
        cin >> receptionistChoice;
        } while (receptionistChoice < 1 || receptionistChoice > 3);
        switch (receptionistChoice) {
            case 1: { // Jamie asks the receptionist what will the dentist do?
                performReceptionistInteraction(anxietyLevel, bill, receptionistChoice);
                break;
            }
            case 2: { // Jamie asks the receptionist how long will the procedure take?
                performReceptionistInteraction(anxietyLevel, bill, receptionistChoice);
                break;
            }
            case 3: { // Jamie asks the receptionist for candies.
                performReceptionistInteraction(anxietyLevel, bill, receptionistChoice, totalCandyTaken);
                break;
            }
        }
        break;
        }
        case 3: { // Jamies chooses to enter the dentist's office
        if (cartoonCount > 0) {
        updateAnxietyLevel(anxietyLevel,-1);
        cout << "Jamie notices there's a TV with the same cartoon he was watching in the waiting room! Anxiety has decreased by 1 since Jamie is feeling at ease." << endl;
        } else if (anxietyLevel >= 1 && anxietyLevel <= 5) {
        if (!(comicBookCount > 0 || videoGameCount > 0 || doodleCount > 0)){
        updateAnxietyLevel(anxietyLevel,1);
        cout << "Jamie is intimidated by the dental tools. Anxiety has increased by 1." << endl;
        }
        }
        int dentistRoomChoice;
        do {
        cout << "Please select an action:\n1. Speak with the dentist\n2. Choose a toy to hold during the visit" << endl;
        cin >> dentistRoomChoice;
        } while (dentistRoomChoice < 1 || dentistRoomChoice > 2);
        switch (dentistRoomChoice) {
            case 1:
            procedure_type = performDentistRoomAction(anxietyLevel, bill, dentistRoomChoice, dentistConsultCount,procedure);
            break;
            case 2:
            procedure_type = performDentistRoomAction(anxietyLevel, bill, dentistRoomChoice, dentistConsultCount,procedure);
            break;
            }
        }
        case 4: {// Jamie chooses to leave the dental office due to high anxiety level.
            updateAnxietyLevel(anxietyLevel,-3);
            updateCost(bill,MISSED_APPOINTMENT_FEE);
            cout << "Leaving the dental office brings Jamie immediate relief. However, he will incur a $" << MISSED_APPOINTMENT_FEE << " Missed Appointment Fee\". Anxiety has decreased by 3." << endl;
            break;
        }
    }
    } while (choice != 4 && !procedure);
    displayFinalSummary(bill, anxietyLevel, comicBookCount, videoGameCount, cartoonCount, doodleCount, relaxationCount, totalCandyTaken, dentistConsultCount, totalToysTaken, choice, procedure_type);
    // End of simulation
    return 0;
}


void performWaitingRoomActivity(int& anxiety, double& bill, int select_activity,int& activity)
{
  switch(select_activity)
{
  case 1:
    updateAnxietyLevel(anxiety, -2);
    cout << "The reading calms Jamie. Anxiety has decreased by 2." << endl;
    break;
  case 2:
    updateAnxietyLevel(anxiety, -3);
    updateCost(bill,VIDEO_GAME_COST);
    cout << "The video game calms Jamie with a $" << VIDEO_GAME_COST << " charge. Anxiety has decreased by 3" << endl;
    break;
  case 3:
    updateAnxietyLevel(anxiety,-2);
    cout << "Watching cartoon eases Jamie's nerves. Anxiety has decreased by 2." << endl;
    break;
  case 4:
    updateAnxietyLevel(anxiety,1);
    updateCost(bill, DRAWING_KIT_COST);
    cout << "The drawing kit costs $" << DRAWING_KIT_COST << ". This causes Jamie a spike in anxiety by 1." << endl;
    break;
  case 5:
    updateAnxietyLevel(anxiety,1);
    updateCost(bill, COMFORT_CHARGE);
    cout << "Jamie has incurred a $" << COMFORT_CHARGE << " comfort charge and is forced to ruminate on the impending visit. Anxiety has increased by 1." << endl;
    break;  
}
  activity++;
}
void performReceptionistInteraction(int& anxiety, double& bill, int select_activity,int& activity)
{
  switch(select_activity)
{
  case 3:
    int candiesTaken;
    do{
    cout << "The receptionist smiles and shows Jamie a jar of candies.\nHow many candies will Jamie take? (0-5):";
    cin >> candiesTaken;
    } while (candiesTaken < 0 || candiesTaken > 5);
    activity += candiesTaken;
    updateCost(bill, candiesTaken * CANDY_COST);
    cout << "This will be $" << candiesTaken * CANDY_COST<< " since each candy is $" << CANDY_COST << "!" << endl;
    if (candiesTaken == 2) {
    updateAnxietyLevel(anxiety,-2);
    cout << "Having received 2 candies, Jamie's anxiety has decreased by 2." << endl;
    } 
    else if (candiesTaken >= 3) {
    updateAnxietyLevel(anxiety,-4);
    cout << "Having received " << candiesTaken << " candies, Jamie's anxiety has decreased by 4." << endl;
    }
    break;
}
}
void performReceptionistInteraction(int& anxiety, double& bill, int select_activity)
{
  switch(select_activity)
{
  case 1:
    updateAnxietyLevel(anxiety,1);
    cout << "Hearing about the procedures makes Jamie slightly nervous. Anxiety has increased by 1." << endl;
    break;
  case 2:
    updateAnxietyLevel(anxiety,-1);
    cout << "The receptionist informs Jamie that the procedure usually takes about 30 minutes. Knowing this info eases Jamie's anxiety a bit by 1." << endl;
    break;
}
}
int performDentistRoomAction(int& anxiety, double& bill, int select_activity,int& activity, bool& procedure)
{
    switch(select_activity)
    {
    case 1:
        updateAnxietyLevel(anxiety,-2);
        updateCost(bill,DENTIST_CONSULT_COST);
        activity++;
        cout << "The dentist explains the process to Jamie, which reassures him, but costs him $"<< DENTIST_CONSULT_COST << ". Anxiety has decreased by 2." << endl;
        break;
    case 2:
        updateAnxietyLevel(anxiety,-3);
        updateCost(bill,TOY_COST);
        activity++;
        cout << "Jamie chooses a soft plush toy which makes him feel safer. This costs $" << TOY_COST << ", but anxiety has decreased by 3." << endl;
        break;
    }
    int dentalProcedureChoice;
    if (anxiety < 6){
        do {
            cout << "Please select a dental procedure:\n1. Standard checkup\n2. Teeth cleaning\n3. Cavity filling\n4. Specialist consultation" << endl;
            cin >> dentalProcedureChoice;
        } while (dentalProcedureChoice < 1 || dentalProcedureChoice > 4);
        switch (dentalProcedureChoice) {
            case 1: // Jamie chooses a standard checkup.
                DentalProcedure(anxiety,bill,dentalProcedureChoice,procedure);
                break;
            case 2: // Jamie chooses teeth cleaning.
                DentalProcedure(anxiety,bill,dentalProcedureChoice,procedure);
                break;
            case 3: // Jamie chooses cavity filling.
                DentalProcedure(anxiety,bill,dentalProcedureChoice,procedure);
                break;
            case 4: // Jamie chooses a specialist consultation.
                DentalProcedure(anxiety,bill,dentalProcedureChoice,procedure);
                break;
        }
    } else
        cout << "Jamie is very anxious! Going back to the main menu!" << endl;
        return dentalProcedureChoice;
    }
void DentalProcedure(int& anxiety, double& bill, int select_activity,bool& activity){
switch(select_activity)
{
  case 1: // Jamie chooses a standard checkup.
    updateAnxietyLevel(anxiety,1);
    updateCost(bill,CHECKUP_COST);
    cout << "Jamie undergoes a routine checkup. This costs $" << CHECKUP_COST << ", and anxiety has increased by 1." << endl;
    break;
case 2: // Jamie chooses teeth cleaning.
    updateAnxietyLevel(anxiety,2);
    updateCost(bill,TEETH_CLEANING_COST);
    cout << "Jamie opts for teeth cleaning for $" << TEETH_CLEANING_COST<< ". The sensation and sound of the cleaning tools has increased his anxiety by 2." << endl;
    break;
case 3: // Jamie chooses cavity filling.
    updateAnxietyLevel(anxiety,3);
    updateCost(bill,CAVITY_FILLING_COST);
    cout << "A cavity is detected and filled for $" << CAVITY_FILLING_COST<< ". Anxiety has increased by 3 since the filling procedure can be quite nerve-wracking." << endl;
    break;
case 4: // Jamie chooses a specialist consultation.
    updateAnxietyLevel(anxiety,2);
    updateCost(bill,SPECIALIST_CONSULT_COST);
    cout << "Jamie needs advice from a specialist and gets a consultation for $"<< SPECIALIST_CONSULT_COST<< "This increases Jamie's anxiety by 2 since this implies a potential issue." << endl;
    break;
}
    activity = true;
}
void updateAnxietyLevel(int& anxietylevel,int anx_change)
{
    if(anxietylevel + anx_change <= MAX_ANXIETY && anxietylevel + anx_change >= MIN_ANXIETY)
      anxietylevel+=anx_change;
    else if(anxietylevel > MAX_ANXIETY)
      anxietylevel = 10;
    else if (anxietylevel < MIN_ANXIETY)
      anxietylevel = 0;
    cout<<"Current Anxiety: "<<anxietylevel<<endl;
}
void updateCost(double& totalbill, const double billadd){

    totalbill+=billadd;
    cout<<"Current Bill: "<<totalbill<<endl;
}
void displayFinalSummary(double bill, int anxietyLevel, int comicBookCount, int videoGameCount, int cartoonCount, int doodleCount, int relaxationCount, int totalCandyTaken, int dentistConsultCount, int totalToysTaken, int choice, int procedure_type)
{
    // Display final summary
    cout << "Final anxiety level: " << anxietyLevel << endl;
    cout << "Billing Details:\n-----------------\n";
    if (comicBookCount > 0)
        cout << "Comic Books Read (" << comicBookCount << "): $0" << endl;
    if (videoGameCount > 0)
        cout << "Video Games Played(" << videoGameCount << "): $" << videoGameCount * VIDEO_GAME_COST << endl;
    if (cartoonCount > 0)
        cout << "Cartoons Watched(" << cartoonCount << "): $0\n";
    if (doodleCount > 0)
        cout << "Papers Doodled (" << doodleCount << "): $" << doodleCount * DRAWING_KIT_COST << endl;
    if (relaxationCount > 0)
        cout << "Times Relaxed in a Plush Armchair (" << relaxationCount << "): $" << relaxationCount * COMFORT_CHARGE << endl;
    if (totalCandyTaken > 0)
        cout << "Candies Taken (" << totalCandyTaken << "): $" << totalCandyTaken * CANDY_COST << endl;
    if (dentistConsultCount > 0)
        cout << "Times Consulted the Dentist (" << dentistConsultCount << "): $" << dentistConsultCount * DENTIST_CONSULT_COST << endl;
    if (totalToysTaken > 0)
        cout << "Toys Taken (" << totalToysTaken << "): $" << totalToysTaken * TOY_COST << endl;
    if (choice == 4)
        cout << "Missed Appointment Fee: $" << MISSED_APPOINTMENT_FEE << ".\n";
    else {
        if (procedure_type == 1)
            cout << "Standard Checkup Procedure: $" << CHECKUP_COST << ".\n";
        else if (procedure_type == 2)
            cout << "Teeth Cleaning Procedure: $" << TEETH_CLEANING_COST << ".\n";
        else if (procedure_type == 3)
            cout << "Cavity Filling Procedure: $" << CAVITY_FILLING_COST << ".\n";
        else if (procedure_type == 4)
            cout << "Specialist Consultation: $" << SPECIALIST_CONSULT_COST << ".\n";
    }
    cout << "-----------------\nTotal Amount Due: $" << bill << endl;
}
