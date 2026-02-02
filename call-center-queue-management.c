
#include <stdio.h>
#define MAX 5

int queue[MAX], front = 0, rear = -1, count = 0, ticketCounter = 1000;

void enqueue() {
    if (count == MAX) {
        printf("Queue Full! All lines busy. Try later.\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = ticketCounter++;
    count++;
    printf("Call added! Ticket: %d, Position: %d\n", queue[rear], count);
}

void dequeue() {
    if (count == 0) {
        printf("No calls waiting.\n");
        return;
    }
    printf("Serving Ticket: %d\n", queue[front]);
    front = (front + 1) % MAX;
    count--;

    if (count > 0)
        printf("Next: Ticket #%d\n", queue[front]);
}

void display() {
    if (count == 0) {
        printf("\nNo calls waiting. All reps free.\n");
        return;
    }

    printf("\n=== QUEUE STATUS ===\nWaiting: %d/%d calls\n", count, MAX);
    printf("Pos | Ticket\n----|-------\n");

    int curr = front;
    for (int i = 1; i <= count; i++) {
        printf("%-3d | %-4d%s\n", i, queue[curr], i == 1 ? " (Next)" : "");
        curr = (curr + 1) % MAX;
    }
}

void stats() {
    printf("\n--- STATISTICS ---\n");
    printf("Status: %s\nLoad: %d/%d (%.0f%%)\n",
           count == 0 ? "EMPTY" : count == MAX ? "FULL" : "ACTIVE",
           count, MAX, (float)count / MAX * 100);
}

int main() {
    int choice;

    printf("=== CALL CENTER HELP DESK ===\nCapacity: %d calls\n", MAX);

    while (1) {
        printf("\n1.Add 2.Serve 3.Display 4.Stats 5.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: stats(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
