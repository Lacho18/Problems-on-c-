#include <iostream>
#include <vector>

using namespace std;

bool equalVectiors(vector<int> firstVector, vector<int> secondVector) {
    int equals = 0;

    for (int i = 0; i < firstVector.size(); i++) {
        for (int j = 0; j < secondVector.size(); j++) {
            if (firstVector[i] == secondVector[j]) {
                equals++;
                break;
            }
        }
    }

    if (equals == firstVector.size()) {
        return true;
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if((nums[i] + nums[j] + nums[k]) == 0) {
                    vector<int> newArray = {nums[i], nums[j], nums[k]};
                    if (result.size() != 0) {
                        bool isEqual = false;
                        int equals = 0;
                        for (int l = 0; l < result.size(); l++) {
                            for (int m = 0; m < result[l].size(); m++) {
                                for (int s = 0; s < newArray.size(); s++) {
                                    if (result[l][m] == newArray[s]) {
                                        equals++;
                                        break;
                                    }
                                }
                                
                            }
                            if (equals != newArray.size()) {
                                result.push_back(newArray);
                                isEqual = true;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                        
                    }
                    else {
                        result.push_back(newArray);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<int> masiv = {0, 1, 1, -2 };

    vector<vector<int>> resultVector = threeSum(masiv);

    for (int i = 0; i < resultVector.size(); i++) {
        for (int j = 0; j < resultVector[i].size(); j++) {
            cout << resultVector[i][j] << " ";
        }
        cout << " " << endl;
    }
}
