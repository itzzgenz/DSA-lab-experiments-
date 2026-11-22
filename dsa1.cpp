#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int tickets[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue (Add Customer)
    void enqueue(int ticket)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        tickets[rear] = ticket;

        cout << "Ticket " << ticket << " added successfully.\n";
    }

    // Dequeue (Serve Customer)
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Ticket " << tickets[front] << " served successfully.\n";
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    // Display Queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCustomers in Queue:\n";
        for (int i = front; i <= rear; i++)
        {
            cout << tickets[i] << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice, ticket;

    do
    {
        cout << "\n===== Ticket Booking Queue Menu =====\n";
        cout << "1. Enqueue Customer\n";
        cout << "2. Dequeue Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Ticket Number: ";
            cin >> ticket;
            q.enqueue(ticket);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}