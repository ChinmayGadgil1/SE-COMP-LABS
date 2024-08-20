#include <iostream>

using namespace std;

int main()
{
    const int num_candidates = 5;
    int votes[num_candidates] = {0}; 
    int spoiltballots = 0;           
    int vote;

    cout << "Enter the votes (Enter -1 to terminate process): " << endl;
    while (cin >> vote && vote != -1)
    {
        if (vote >= 1 && vote <= num_candidates)
        {
            votes[vote - 1]++;
        }
        else
        {
            spoiltballots++;
        }
    }

    cout << "Vote count for each candidate is: " << endl;
    for (int i = 0; i < num_candidates; i++)
    {
        cout << "Candidate " << i + 1 << ": " << votes[i] << " votes" << endl;
    }
    cout << "Number of spoilt ballots is: " << spoiltballots << endl;

    return 0;
}
