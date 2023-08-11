#include <bits/stdc++.h>
using namespace std;

/*
An animal shelter that houses cats and dogs wants to ensure no pet has to wait too long for a forever home. Therefore, anyone who comes to adopt a pet can pick the species (cat or dog) but not the specific animal; they are assigned the animal of that species that has been in the shelter longest. If there are no animals available of the desired species, they must take the other species. You are given a list of pets in the shelter with their names, species, and time in the shelter at the start of a week. You receive a sequence of incoming people (to adopt pets) and animals (new additions to the shelter) one at a time. Print the names and species of the pets as they are adopted out.
*/

// Time Complexity: O(N log N)
// Space Complexity: O(N log N)

void adoptAPet() {
    priority_queue<pair<int, string>, vector<pair<int, string>>> cat_list;
    priority_queue<pair<int, string>, vector<pair<int, string>>> dog_list;
    string answer;
    cout << "Are you adopting a pet?" << endl;
    cin >> answer;
    if (answer == "yes") {
        string name;
        cout << "Enter your name: ";
        cin >> name;
        string preference;
        cout << "Enter your preference (either dog or cat): ";
        cin >> preference;
        if (preference == "cat") {
            if (cat_list.size() > 0) {
                string curr_pet = cat_list.top().second;
                cat_list.pop();
                cout << name << " " << preference << " " << curr_pet << endl;
            } else if (dog_list.size() > 0) {
                string curr_pet = dog_list.top().second;
                dog_list.pop();
                cout << name << " " << preference << " " << curr_pet << endl;
            } else
                cout << "No more pets left!" << endl;
            }
        else {
            if (dog_list.size() > 0) {
                string curr_pet = dog_list.top().second;
                dog_list.pop();
                cout << name << " " << preference << " " << curr_pet << endl;
            } else if (dog_list.size() > 0) {
                string curr_pet = cat_list.top().second;
                cat_list.pop();
                cout << name << " " << preference << " " << curr_pet << endl;
            } else
                cout << "Sorry, no more pets" << endl;
        }
    } else {
        string breed;
        cout << "Enter breed: " << endl;
        cin >> breed;
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        if (breed == "dog")
            dog_list.push({1, name});
        else
            cat_list.push({1, name});
    }
}

int main()
{
    priority_queue<pair<int, string>, vector<pair<int, string>>> cat_list;
    priority_queue<pair<int, string>, vector<pair<int, string>>> dog_list;
    dog_list.push({4, "Sadie"});
    cat_list.push({7, "Woof"});
    dog_list.push({2, "Chirpy"});
    dog_list.push({1, "Lola"});
    while (cat_list.size() > 0 && dog_list.size() > 0) {
        adoptAPet();
    }
}