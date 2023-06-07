#include <iostream>
#include <string>

using namespace std;

// class for player
class player {
    private:
        string name;
    public:
        //setters and getters for players name

        void setName(string Name) {
            name = Name;
        }
        string getName() {
            return name;
        }
        // varibles for heatlh, armor, damage, and gold the player has
        int Health = 10;
        int Armor = 10;
        int Damage = 2;
        int Gold = 0;
        
};

// child class for smelly little goblins
class enemy{
    public:
        int Health = 5;
        int Armor = 5;
        int Damage = 2;
        int Gold = 4;
        
};

// class to represent a town where player can purchase better armor weapons and heal
class town{

};

// main function
int main(){
    // varibles
    player Player1;
    string PlName;
    string Answer;
    //array to see if the attack connects
    int onHit[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    bool GameRunning = true;
    enemy Goblin1;
    // Asks the player for the characters name and asks if they want to change it befor game begins
    do {
        cout << "What is the name of your Wanderer? \n";
        cin >> PlName;
        Player1.setName(PlName);
        cout << "Conferm that your Wanderers name is " << Player1.getName() << " yes or no?" << endl;
        cin >> Answer;
    }while (Answer == "no" || Answer == "No");
    
    while (GameRunning == true) {
        // test enemy encounter
        cout << "Test enemy encounter \n";
        cout << "Attack? yes or no \n";
        cin >> Answer;
        // picks a number between 1 and 20 for attack ACs and other stuff
        int G = rand() % 20;
        cout << G << endl;
        //checks if the player wants to attack and onHit is greater than the enemys AC
        if (Answer == "yes" || Answer == "Yes" && onHit[0] >= Goblin1.Armor) {
            cout << Player1.getName() << " Attacks! \n";
            cout << "enemy takes " << Player1.Damage << " damage!" << endl;
            Goblin1.Health = Goblin1.Health - Player1.Damage;
         // end of if statment
        } else if (onHit[G] < Goblin1.Armor) {
            cout << Player1.getName() << " Attacks! \n";
            cout << "bit completly misses \n";
        }


        // enemy attacking code
        cout << G << endl;
        cout << "The enemy attacks! \n";
        if (onHit[19] >= Player1.Armor) {
            cout << Player1.getName() << " takes " << Goblin1.Damage << " damage!" << endl;
            Player1.Health = Player1.Health - Goblin1.Damage;
        }
        else {
            cout << "But it misses \n";
        }
        //checks to see if the enemy health is 0 and if the player is still alive
        // if player is still alive at end of encounter than they will get gold and a victory message
        if (Goblin1.Health <= 0 && Player1.Health > 0) {
            cout << "Victory you gain " << Goblin1.Gold << " Gold coins!" << endl;
            Player1.Gold = Player1.Gold + Goblin1.Gold;
            // enemy heath increases the more gold a player has 
            Goblin1.Health = Goblin1.Health + Player1.Gold;
            break;
        }
        else if (Player1.Health <= 0) {
            cout << "Your wander has fallen \n";
            cout << "Game over \n";
            break;
   //end of while loop
   } 

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
