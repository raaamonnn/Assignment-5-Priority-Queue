#include "header.h"
#include "PriorityQueue.h"
#include <queue>
#include<utility>
#include "math.h"


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
//	if(true)
//	{
//	cout << "***************************************************************************\n";
//	cout << "* SIMULATING AN AFTERNOON IN AN EMERGENCY ROOM WITH MY OWN PRIORITY QUEUE *\n";
//	cout << "***************************************************************************\n";
//	PriorityQueue pQueue;//custom Prio Queue
//
//	//Inserted All at noon
//	pQueue.insert("Bob Bleeding", 6);
//	pQueue.insert("Frank Feelingbad", 3);
//	pQueue.insert("Cathy Coughing", 5);
//	pQueue.insert("Paula Pain", 4);
//	pQueue.insert("Alice Allment", 7);
//	pQueue.insert("Irene Ill", 1);
//	pQueue.insert("Tom Temperature", 8);
//
//	pQueue.display();
//	cout << endl;
//	double time = 12.00;double lastPatient =0;
//
//	char newPatient = ' ';
//	while(time <= 23.59 && newPatient != '0')
//	{
//
//		cout << "Would you like to Enter a New Patient into the Priority Queue? (Y/N) Enter 0 to Exit Program: ";
//		cin.get(newPatient);
//		cin.ignore();
//
//		cout << endl;
//
//		newPatient = toupper(newPatient);
//
//		string patientName;
//		if(newPatient == 'Y')
//		{
//			cout << "Please Enter The Name of the New Patient: ";
//			getline(cin,patientName);
//			cout << endl;
//
//			int patientPriority;
//			cout << "Please Enter The Priority of the New Patient (Enter 100 for Life Threatening Injuries): ";
//			cin  >> patientPriority;
//			cin.ignore();
//
//			cout << endl;
//
//			if(patientPriority == 100)
//			{
//				double currentTime;
//				cout << "Please Enter The Time You're Operation Starts: ";
//				cin  >> currentTime;
//				cin.ignore();
//				lastPatient = time - currentTime;
//
//				cout << "\n*** STARTING TIME: "<< time << " ***\n";
//
//				time = currentTime;
//				//if patientPriority is 100 it should stop the current patients operation and do the 100 priority one
//			    //after 100 priority is done the other patients operation should continue with the rest of the time (total 25 min)
//
//				if((int)(time*100)%100>60)
//				{
//					time +=1;
//					time -= .6;
//				}
//				cout << "\n*** INTERUPRING " << pQueue.showFront() << " OPERATION DUE TO " << patientName << " CRITICAL INJURY AT TIME: "<< time << " ***\n\n";
//
//			}
//			else
//			{
//				pQueue.insert(patientName, patientPriority);
//			}
//		}
//
//		cout << "*** STARTING TIME: " << time << " ***\n";
//		time += .25;
//
//		if(((int)(time*100)%100)>60)
//		{
//			time +=1;
//			time -= .6;
//		}
//		cout << "*** ENDING TIME: "<< time << " ***\n";
//
//		if(lastPatient < 0)
//		{
//			cout << "Patient: " << patientName << " finished the operation\n";
//			cout << "\n***FINISHING THE UNCOMPLETED OPERATION FROM " << pQueue.showFront() << " ***\n";
//			cout << "*** STARTING TIME: "<< time << " ***\n";
//			double x = ((lastPatient) + 0.25);
//			time += x;
//			if((int)(time*100)%100>60)
//			{
//				time +=1;
//				time -= .6;
//			}
//			cout << "*** ENDING TIME: "<< time << " ***\n";
//			lastPatient = 0;
//		}
//		if(!pQueue.isEmpty())
//		{
//			pQueue.del();
//		}
//		else
//		{
//			cout << "***THE HOSPITAL IS EMPTY***\n";
//		}
//	}
//
//	pQueue.display();
//	}
	//---------------------------------------------------------------------------------------------------

	cout << endl << endl << endl;

	cout << "***********************************************************************\n";
	cout << "* SIMULATING AN AFTERNOON IN AN EMERGENCY WITH THE STL PRIORITY QUEUE *\n";
	cout << "***********************************************************************\n";

	priority_queue<pair<string,int>> stlPQueue;//STL Prio Queue

	//Inserted All at noon
	stlPQueue.push(make_pair("Bob Bleeding", 6));
	stlPQueue.push(make_pair("Frank Feelingbad", 3));
	stlPQueue.push(make_pair("Cathy Coughing", 5));
	stlPQueue.push(make_pair("Paula Pain", 4));
	stlPQueue.push(make_pair("Alice Allment", 7));
	stlPQueue.push(make_pair("Irene Ill", 1));
	stlPQueue.push(make_pair("Tom Temperature", 8));

	cout << endl;
	double time = 12.00;double lastPatient =0;

	char newPatient = ' ';
	while(time <= 23.59 && newPatient != '0')
	{

		cout << "Would you like to Enter a New Patient into the Priority Queue? (Y/N) Enter 0 to Exit Program: ";
		cin.get(newPatient);
		cin.ignore();

		cout << endl;

		newPatient = toupper(newPatient);

		string patientName;
		if(newPatient == 'Y')
		{
			cout << "Please Enter The Name of the New Patient: ";
			getline(cin,patientName);
			cout << endl;

			int patientPriority;
			cout << "Please Enter The Priority of the New Patient (Enter 100 for Life Threatening Injuries): ";
			cin  >> patientPriority;
			cin.ignore();

			cout << endl;

			if(patientPriority == 100)
			{
				double currentTime;
				cout << "Please Enter The Time You're Operation Starts: ";
				cin  >> currentTime;
				cin.ignore();
				lastPatient = time - currentTime;

				cout << "\n*** STARTING TIME: "<< time << " ***\n";

				time = currentTime;
				//if patientPriority is 100 it should stop the current patients operation and do the 100 priority one
			    //after 100 priority is done the other patients operation should continue with the rest of the time (total 25 min)

				if((int)(time*100)%100>60)
				{
					time +=1;
					time -= .6;
				}
				cout << "\n*** INTERUPRING ";
				stlPQueue.top();
				cout << " OPERATION DUE TO " << patientName << " CRITICAL INJURY AT TIME: "<< time << " ***\n\n";
			}
			else
			{
				stlPQueue.push(make_pair(patientName, patientPriority));
			}
		}

		cout << "*** STARTING TIME: " << time << " ***\n";
		time += .25;

		if(((int)(time*100)%100)>60)
		{
			time +=1;
			time -= .6;
		}
		cout << "*** ENDING TIME: "<< time << " ***\n";
		if(lastPatient < 0)
		{
			cout << "Patient: " << patientName << " finished the operation\n";
			cout << "\n***FINISHING THE UNCOMPLETED OPERATION FROM ";
			stlPQueue.top();
			cout << " ***\n";
			cout << "*** STARTING TIME: "<< time << " ***\n";
			double x = ((lastPatient) + 0.25);
			time += x;
			if((int)(time*100)%100>60)
			{
				time +=1;
				time -= .6;
			}
			cout << "*** ENDING TIME: "<< time << " ***\n";
			lastPatient = 0;
		}
		if(!stlPQueue.empty())
		{
			cout << "Patient: ";stlPQueue.top().first;
			cout << " finished the operation\n";
			stlPQueue.pop();
		}
		else
		{
			cout << "***THE HOSPITAL IS EMPTY***\n";
		}
	}

return 0;
}
