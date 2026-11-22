
#include <iostream>
using namespace std;

void heapify(int score[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && score[left] > score[largest])
        largest = left;

    if (right < n && score[right] > score[largest])
        largest = right;

    if (largest != i) {
        swap(score[i], score[largest]);
        heapify(score, n, largest);
    }
}

void heapSort(int score[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(score, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(score[0], score[i]);
        heapify(score, i, 0);
    }
}

int main() {
    int n, score[100];

    cout << "Enter number of players: ";
    cin >> n;

    cout << "Enter player scores: ";
    for (int i = 0; i < n; i++)
        cin >> score[i];

    heapSort(score, n);

    cout << "Leaderboard (Ascending Scores): ";
    for (int i = 0; i < n; i++)
        cout << score[i] << " ";

    return 0;
}
