#include <iostream>
#include <string>
#define MAX_PATIENTS 100  // Maximum number of patients
using namespace std;


// Patient class to store patient details
class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    string diseases;
    int number;
    string address;
    string bloodgroup;
    

    // Constructor to initialize a patient
    Patient() {
        id = -1;  // Initialize id as -1 to indicate that it's empty
    }

    Patient(int id, string name, int age, string gender, string diseases,int number, string address, string bloodgroup) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->diseases = diseases;
        this->number = number;
        this->address = address;
        this->bloodgroup = bloodgroup;
    }
};

// Hospital class to manage all patients
class Hospital {
private:
	Patient patients[MAX_PATIENTS];
    int patientCount;

public:
    // Constructor to initialize the patient count
    Hospital() {
        patientCount = 0;
    }

    // Add new patient
    void addPatient(int id, string name, int age, string gender, string diseases, int number, string address, string bloodgroup) {
        

        Patient newPatient(id, name, age, gender, diseases, number, address, bloodgroup );
        patients[patientCount] = newPatient;
        patientCount++;
        cout << "\nPatient added successfully." << endl;
    }

    // Delete patient by ID
    void deletePatient(int id) {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].id == id) {
                // Shift all patients after the deleted patient to the left
                for (int j = i; j < patientCount - 1; ++j) {
                    patients[j] = patients[j + 1];
                }
                patientCount--;
                cout << "\nPatient record deleted successfully." << endl;
                return;
            }
        }
        cout << "\nPatient not found." << endl;
    }

    // Modify patient details by ID
    void modifyPatient(int id) {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].id == id) {
                cout << "\nEnter new name: ";
                cin >> patients[i].name;
                cout << "\nEnter new age: ";
                cin >> patients[i].age;
                cout << "\nEnter new gender: ";
                cin >> patients[i].gender;
                cout << "\nEnter new diseases: ";
                cin >> patients[i].diseases;
                cout << "\nEnter new Contact: ";
                cin >> patients[i].number;
                cout << "\nEnter new Address: ";
                cin >> patients[i].address;
                cout << "\nEnter new BloodGroup: ";
                cin >> patients[i].bloodgroup;
                cout << "\nPatient details updated successfully." << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }

    // Check patient details by ID
    void checkPatient(int id) {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].id == id) {
                cout << "\nPatient ID: " << patients[i].id << endl;
                cout << "\nName: " << patients[i].name << endl;
                cout << "\nAge: " << patients[i].age << endl;
                cout << "\nGender: " << patients[i].gender << endl;
                cout << "\nDiseases: " << patients[i].diseases << endl;
                cout << "\nNumber: " << patients[i].number << endl;
                cout << "\nAddress: " << patients[i].address << endl;
                cout << "\nBloodGroup: " << patients[i].bloodgroup << endl;
                return;
            }
        }
        cout << "\nPatient not found." << endl;
    }
};

int main() {
	
	
	cout<<"\n";
    cout<<"\t\t****************************************************************************\n";
 	cout<<"\t\t*\t\t\t__________________________________                 *\n";
	cout<<"\t\t*\t\t\t|                       _______   |                *\n";
	cout<<"\t\t*\t\t\t| |     |      /\\      |       |  |                *\n";
	cout<<"\t\t*\t\t\t| |     |     /  \\     |       |  |                *\n";
	cout<<"\t\t*\t\t\t| |_____|    /    \\    |_______   |                *\n";
	cout<<"\t\t*\t\t\t| |     |   /______\\           |  |                *\n";
	cout<<"\t\t*\t\t\t| |     |  /        \\  |       |  |                *\n";
	cout<<"\t\t*\t\t\t| |     | /          \\ |_______|  |                *\n";
	cout<<"\t\t*\t\t\t|_________________________________|                *\n";
	cout<<"\t\t*\t\t\t\t\t\t\t\t\t   *\n";
 cout<<"\t\t****************************************************************************\n";
    Hospital hospital;
    int choice;
    int id, age, number;
    string name, gender, diseases, bloodgroup, address;

    while (true) {
        cout << "\nHospital Administration System\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient Record\n";
        cout << "3. Modify Patient Details\n";
        cout << "4. Check Patient Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: \n\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter patient ID: ";
                cin >> id;
                cout << "\nEnter patient name: ";
                cin >> name;
                cout << "\nEnter patient age: ";
                cin >> age;
                cout << "\nEnter patient gender: ";
                cin >> gender;
                cout << "\nEnter patient diseases: ";
                cin >> diseases;
                cout << "\nEnter patient Contact Number: ";
                cin >> number;
                cout << "\nEnter patient Address: ";
                cin >> address;
                cout << "\nEnter patient BloodGroup: ";
                cin >> bloodgroup;
                hospital.addPatient(id, name, age, gender, diseases, number, address, bloodgroup);
                break;

            case 2:
                cout << "Enter patient ID to delete: ";
                cin >> id;
                hospital.deletePatient(id);
                break;

            case 3:
                cout << "Enter patient ID to modify: ";
                cin >> id;
                hospital.modifyPatient(id);
                break;

            case 4:
                cout << "Enter patient ID to check details: ";
                cin >> id;
                hospital.checkPatient(id);
                break;

            case 5:
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
