#include<iostream>
#include<string>
using namespace std;

// Arrays used to store application records
string name[50];
string rollno[50];
string cnic[50];
string board[50];
string document_type[50];
string status[50];
string service_type[50];
string request_id[50];
string payment[50];
int challan[50];

// Stores total number of applications submitted
int total = 0;

// Function declarations
void mainmenu();
void student_login();
void admin_login();
void student_panel();
void admin_panel();
void attestion_or_verification();
void generate_challan(int n);
void pay_challan();
void tracking_status();
void view_allrequests();
void update_status();
void applications_summary();

int main()
{
	// Program starts from the main menu
	mainmenu();
	return 0;
}
// Displays the main menu and directs users to student/admin panels
void mainmenu()
{
	int choice;
	do
	{
		cout << "\n==========IBCC AND ALL BOARDS ATTESTATION AND VERIFICATION MANAGEMENT SYSTEM==========\n";
		cout << "Enter your choice :\n";
		cout << "1. Student Login\n";
		cout << "2. Admin login\n";
		cout << "3. Exit\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			student_login();
			break;
		case 2:
			admin_login();
			break;
		case 3:
			cout << "\nProgram terminated!\n";
			break;
		default:
			cout << "\nInvalid choice entered!\n";
			break;
		}
	} while (choice != 3);

}
// Handles student login
void student_login()
{
	string rollno, password;
	cout << "\nEnter your roll no :\n";
	cin >> rollno;
	cout << "Enter the CNIC last four digits :\n";
	cin >> password;

	student_panel();
}
// Displays options available to students
void student_panel()
{
	int choice;
	do
	{
		cout << "\n=====Student Panel=====\n";
		cout << "1. Apply for attestation or Verification\n";
		cout << "2. Track your application\n";
		cout << "3. Pay challan\n";
		cout << "4. Logout\n";
		cout << "Enter your choice :\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			attestion_or_verification();
			break;
		case 2:
			tracking_status();
			break;
		case 3:
			pay_challan();
			break;
		case 4:
			cout << "\nLogged out\n";
			break;
		default:
			cout << "\nInvalid choice entered!\n";
			break;
		}
	} while (choice != 4);
}
// Allows students to submit attestation or verification applications
void attestion_or_verification()
{
	if (total >= 50)
	{
		cout << "\napplications maximum limit reached\n";
		return;
	}
	int type;
	request_id[total] = "APP" + to_string(1000 + total);

	cout << "\n=====Application Form=====\n";
	cout << "Enter your name :\n";
	getline(cin>>ws,name[total]);
	cout << "Enter roll no:\n";
	cin >> rollno[total];
	cout << "Enter CNIC :\n";
	cin >> cnic[total];
	cout << "Enter your BOARD :\n";
	getline(cin>>ws, board[total]);
	cout << "Enter the document type :\n";
	getline(cin >>ws, document_type[total]);

	cout << "Enter your service type :\n";
	cout << "1. Attestation\n";
	cout << "2. Verification\n";
	cin >> type;

	if (type == 1)
	{
		service_type[total] = "Attestation";
		challan[total] = 3500;
	}
	else if (type == 2)
	{
		service_type[total] = "Verification";
		challan[total] = 2000;
	}
	else
		cout << "Invalid type!\n";

	status[total] = "Pending";
	payment[total] = "Unpaid";
	cout << "Application form submitted successfully!\n";
	cout << "Your Application ID = " << request_id[total] << "\n";

	generate_challan(total);
	total++;

}
// Displays challan details for a specific application
void generate_challan(int n)
{
	cout << "\nFollowing is the generated challan :\n";
	cout << "=====Challan Slip=====\n";
	cout << "Application ID = " << request_id[n] << "\n";
	cout << "Name = " << name[n] << "\n";
	cout << "Roll no = " << rollno[n] << "\n";
	cout << "Service type = " << service_type[n] << "\n";
	cout << "Challan Amount = Rs. " << challan[n] << "\n";
	cout << "Payment status = Unpaid \n";
}
// Allows students to pay challan against an application
void pay_challan()
{
	string id;
	cout << "\nEnter your application id :\n";
	cin >> id;

	cout << "=====Challan Payment=====\n";
	for (int i = 0; i < total; i++)
	{
		if (request_id[i] == id)
		{
			if (payment[i] == "Paid")
				cout << "Challan already paid!\n";
			else 
			{
				payment[i] = "Paid";
				cout << "Payment Successful!\n";
			}

			return;
		}
	}
	cout << "Record not found!\n";
}
// Displays complete application status information
void tracking_status()
{
	string id;
	cout << "\nEnter your application id :\n";
	cin >> id;

	cout << "=====Tracking Status=====\n";
	for (int i = 0; i < total; i++)
	{
		if (request_id[i] == id)
		{
			cout << "Name = " << name[i]<<"\n";
			cout << "Roll no = " << rollno[i] << "\n";
			cout << "Document type = " << document_type[i] << "\n";
			cout << "Challan Amount = Rs. " << challan[i] << "\n";
			cout << "Service Type = " << service_type[i] << "\n";
			cout << "Payment status = " << payment[i] << "\n";
			cout << "Status = " << status[i] << "\n";
			return;
		}
	}
	cout << "Record not found!\n";
}
// Handles administrator login
void admin_login()
{
	string username, password;
	cout << "\nEnter username:\n";
	cin >> username;
	cout << "Enter the password:\n";
	cin >> password;

	if (username == "admin" && password == "seecs@123")
		admin_panel();
	else
		cout << "Invalid admin credentials!\n";
}
// Displays administrator options
void admin_panel()
{
	int choice;
	do
	{
		cout << "\n=====Admin Panel=====\n";
		cout << "1. View all applications\n";
		cout << "2. Update applications status\n";
		cout << "3. Applications Summary\n";
		cout << "4. Logout\n";
		cout << "Enter your choice :\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			view_allrequests();
			break;
		case 2:
			update_status();
			break;
		case 3:
			applications_summary();
			break;
		case 4:
			cout << " Logged out\n";
			break;
		default:
			cout << "Invalid choice entered!\n";
			break;
		}
	} while (choice != 4);

}
// Shows all applications stored in the system
void view_allrequests()
{
	cout << "\n=====All Applications=====\n";
	for (int i = 0; i < total; i++)
	{
		cout << "Record no " << i + 1 << "\n";
		cout << "Application ID = " << request_id[i] << "\n";
		cout << "Name = " << name[i] << "\n";
		cout << "Roll no = " << rollno[i] << "\n";
		cout << "Board = " << board[i] << "\n";
		cout << "Document type = " << document_type[i] << "\n";
		cout << "Service Type = " << service_type[i] << "\n";
		cout << "Status = " << status[i] << "\n";
		cout << "Payment Status = " << payment[i] << "\n";

	}
}
// Allows admin to update application status
void update_status()
{
	string id;
	cout << "\nEnter the Application ID :\n";
	cin >> id;

	cout << "=====Updating the Status=====\n";
	for (int i = 0; i < total; i++)
	{
		if (request_id[i] == id)
		{
			cout << "Current Status = " << status[i] << "\n";
			cout << "New Status (Pending/Completed/Rejected)\n";
			cin >> status[i];
			cout << "Status Updated Successfully!\n";
			return;
		}
	}
	cout << "Record not found!\n";
}
// Displays summary statistics of all applications
void applications_summary()
{
	int pending = 0, completed = 0, rejected = 0;

	for (int i = 0; i < total; i++)
	{
		if (status[i] == "Pending")
			pending++;
		else if (status[i] == "Completed")
			completed++;
		else if (status[i] == "Rejected")
			rejected++;
	}
	cout << "\n=====Applications Summary=====\n";
	cout << "Total Applications = " << total<<"\n";
	cout << "Pending Applications = " << pending << "\n";
	cout << "Completed Applications = " << completed << "\n";
	cout << "Rejected Applications = " << rejected << "\n";
}