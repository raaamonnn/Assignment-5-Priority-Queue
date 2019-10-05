#include "header.h"
#include "PriorityQueue.h"
#include <queue>


//start queue at 1pm
//each patient requires 25 mins
//patients with longest waiting time have the highest priority
//Patients that have live threating injuries will imeadietly be set as the highest priority
//Determine the order in which the patients will be treated
//Create a timer and output each appointement start and end time
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}

int main()
{
	PriorityQueue pQueue;//custom Prio Queue
	priority_queue<string> stlPQueue;//STL Prio Queue

	//Inserted All at noon
	//---------------------------------
	pQueue.insert("Bob Bleeding", 6);
	pQueue.insert("Frank Feelingbad", 3);
	pQueue.insert("Cathy Coughing", 5);
	//---
	pQueue.insert("Paula Pain", 4);

	pQueue.insert("Alice Allment", 7);
	//---
	pQueue.insert("Tom Temperature", 8);
	//---
//	//------------------------------------
//	pQueue.insert("Sam Sneezing", 100);
//	pQueue.insert("Sid Sickly", 100);
//	pQueue.insert("Irene Ill", 1);
//
//
//	pQueue.display();
//
//	pQueue.del();

	double time = 12.00;double lastPatient =0;

	char newPatient = ' ';
	while(time <= 23.59 || newPatient != '0')
	{

		cout << "Would you like to Enter a New Patient into the Priority Queue? (Y/N) Enter 0 to Exit Program";
		cin.get(newPatient);
		cin.ignore();

		cout << endl;

		newPatient = toupper(newPatient);
		if(newPatient == 'Y')
		{
			string patientName;
			cout << "Please Enter The Name of the New Patient: ";
			getline(cin,patientName);
			cout << endl;

			int patientPriority;
			cout << "Please Enter The Priority of the New Patient (Enter 100 for Life Threatening Injuries)";
			cin >> patientPriority;

			if(patientPriority == 100)
			{
				int currentTime;
				cout << "Please Enter The Time You're Operation Starts";
				cin >> currentTime;
				lastPatient = time - currentTime;
				time = currentTime;
				 //if patientPriority is 100 it should stop the current patients operation and do the 100 priority one
															 //after 100 priority is done the other patients operation should continue with the rest of the time (total 25 min)
			}
		}

		cout << "*** STARTING TIME: " << time << " ***\n";
		time += .25;

		if(((int)(time*100)%100)>60)
		{
			cout << (int)(time)+1;
			time = (int)(time)+1;
			cout <<time;
			time += ((time -(int)(time))*100 -60)/100.0;
		}
		cout << "*** ENDING TIME: "<< time << " ***\n";

		if(lastPatient > 0)
		{
			cout << "FINISHING THE UNCOMPLETED OPERATION FROM PRIOR PERSON\n";
			cout << "*** STARTING TIME: "<< time << " ***\n";
			time += lastPatient;
			if((int)(time*100)%100>60)
			{
				time = (int)(time)+1;
				time += ((time -(int)(time))*100 -60)/100.0;
			}
			cout << "*** ENDING TIME: "<< time << " ***\n";
			lastPatient = 0;
		}
		if(!pQueue.isEmpty())
		{
			pQueue.del();
		}
		else
		{
			cout << "***THE HOSPITAL IS EMPTY***\n";
		}
	}
return 0;
}
