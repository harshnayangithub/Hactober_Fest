#include <iostream>
#include <queue>

using namespace std;

// Function to add a job to the deque
void addJob(queue<string> &jobdeque)
{
    string job;
    cout << "Enter the job to be added: ";
    cin >> job;
    jobdeque.push(job);
    cout << "Job added to the deque." << endl;
}

// Function to delete a job from the deque
void deleteJob(queue<string> &jobdeque)
{
    if (!jobdeque.empty())
    {
        cout << "Job removed from the deque: " << jobdeque.front() << endl;
        jobdeque.pop();
    }
    else
    {
        cout << "deque is empty. No job to delete." << endl;
    }
}

// Function to display the jobs in the deque
void displayJobs( queue<string> &jobdeque)
{
    if (!jobdeque.empty())
    {
        cout << "Jobs in the deque:" << endl;
        queue<string> tempdeque = jobdeque;
        while (!tempdeque.empty())
        {
            cout << tempdeque.front() << endl;
            tempdeque.pop();
        }
    }
    else
    {
        cout << "deque is empty. No jobs to display." << endl;
    }
}

int main()
{
    queue<string> jobdeque;
    int choice;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addJob(jobdeque);
            break;
        case 2:
            deleteJob(jobdeque);
            break;
        case 3:
            displayJobs(jobdeque);
            break;
        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    
}
