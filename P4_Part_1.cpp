#include <bits/stdc++.h>

using namespace std;

// Shahd Elnassag
// Problem 4 in Part 1 Dynamic Programming

int maxTreasureValue[1010][31];
bool itemSelected[1010][31];
int treasureQuantity[31];
int goldDepth[31];
int timeCost[31];
int totalTime;
int totalTreasure;

void initialize(){
    memset(maxTreasureValue, -1, sizeof(maxTreasureValue));  // Initialize DP table with -1 (uncomputed state)
    memset(treasureQuantity, 0, sizeof(treasureQuantity));         // Initialize treasure values to 0
    memset(goldDepth, 0, sizeof(goldDepth));                 // Initialize item depths to 0
    memset(timeCost, 0, sizeof(timeCost));                   // Initialize item costs to 0
    memset(itemSelected, false, sizeof(itemSelected));       // Initialize item selection to false
}

int computeMaxTreasure(int remainingTime, int currentItemIndex) {
    // Base case: if time is negative, terminate
    if (remainingTime < 0) {
        return 0;
    }
    // Base case: if all items have been considered, terminate
    if (currentItemIndex == totalTreasure) {
        return 0;
    }
    // If the result has already been computed, return it
    if (maxTreasureValue[remainingTime][currentItemIndex] != -1) {
        return maxTreasureValue[remainingTime][currentItemIndex];
    }

    // Two choices: either include the current item or exclude it
    int valueIfIncluded = 0;
    int valueIfExcluded = 0;

    // If there's enough time to include the current item, calculate the value if included
    if (remainingTime - timeCost[currentItemIndex] >= 0) {
        valueIfIncluded = computeMaxTreasure(remainingTime - timeCost[currentItemIndex], currentItemIndex + 1) + treasureQuantity[currentItemIndex];
    }
    // Calculate the value if the current item is excluded
    valueIfExcluded = computeMaxTreasure(remainingTime, currentItemIndex + 1);

    // Select the option that gives the maximum value
    if (valueIfIncluded > valueIfExcluded) {
        itemSelected[remainingTime][currentItemIndex] = true;
    }

    // Store the result in the DP table
    int result = max(valueIfIncluded, valueIfExcluded);
    return maxTreasureValue[remainingTime][currentItemIndex] = result;
}

int main() {
    int timeAvailable;      // Time available for treasure collection
    bool isFirstCase = true; // Flag to handle output formatting

    // Read the input until EOF
    while (cin >> timeAvailable >> totalTime) {
        if (isFirstCase) {
            isFirstCase = false;
        } else {
            cout << endl;  // Print a blank line between test cases
        }

        // Initialize the DP arrays
        initialize();

        cin >> totalTreasure; // Number of items available
        for (int i = 0; i < totalTreasure; i++) {
            cin >> goldDepth[i] >> treasureQuantity[i];
            timeCost[i] = goldDepth[i] * 3 * totalTime; // Cost is based on depth and weight
        }

        // Compute the maximum treasure value that can be collected within the available time
        cout << computeMaxTreasure(timeAvailable, 0) << endl;

        // Find the items that were selected
        vector<int> selectedItems;
        int remainingTime = timeAvailable;
        for (int i = 0; i < totalTreasure; i++) {
            if (itemSelected[remainingTime][i]) {
                selectedItems.push_back(i);
                remainingTime -= timeCost[i];
            }
        }

        // Output the number of selected items
        cout << selectedItems.size() << endl;

        // Output the details of each selected item
        for (int i = 0; i < selectedItems.size(); i++) {
            cout << goldDepth[selectedItems[i]] << " " << treasureQuantity[selectedItems[i]] << endl;
        }
    }

    return 0;
}
