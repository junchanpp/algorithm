#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int daysDifference(tm date1, tm date2) {
    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);
    return difftime(time2, time1) / (60 * 60 * 24);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string endDateStr, reportDateStr;
        cin >> endDateStr >> reportDateStr;

        vector<string> endDateParts = split(endDateStr, '/');
        vector<string> reportDateParts = split(reportDateStr, '/');

        int endMonth = stoi(endDateParts[0]);
        int endDay = stoi(endDateParts[1]);
        int endYear = stoi(endDateParts[2]);

        int reportMonth = stoi(reportDateParts[0]);
        int reportDay = stoi(reportDateParts[1]);

        tm endDate = {0, 0, 0, endDay, endMonth - 1, endYear - 1900};
        tm reportDate1 = {0, 0, 0, reportDay, reportMonth - 1, endYear - 1900};
        tm reportDate2 = {0, 0, 0, reportDay, reportMonth - 1, endYear - 1900 + 1};
        tm reportDate3 = {0, 0, 0, reportDay, reportMonth - 1, endYear - 1900 - 1};

        int diff1 = daysDifference(endDate, reportDate1);
        int diff2 = daysDifference(endDate, reportDate2);
        int diff3 = daysDifference(endDate, reportDate3);

        string result;
        if (diff1 == 0) {
            result = "SAME DAY";
        } else if (abs(diff1) <= 7) {
            if (diff1 > 0) {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear) + " IS " + to_string(diff1) + " DAY" + (diff1 == 1 ? "" : "S") + " AFTER";
            } else {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear) + " IS " + to_string(-diff1) + " DAY" + (-diff1 == 1 ? "" : "S") + " PRIOR";
            }
        } else if (abs(diff2) <= 7 && reportDate2.tm_year == endDate.tm_year + 1) {
            if (diff2 > 0) {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear + 1) + " IS " + to_string(diff2) + " DAY" + (diff2 == 1 ? "" : "S") + " AFTER";
            } else {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear + 1) + " IS " + to_string(-diff2) + " DAY" + (-diff2 == 1 ? "" : "S") + " PRIOR";
            }
        } else if (abs(diff3) <= 7 && reportDate3.tm_year == endDate.tm_year - 1) {
            if (diff3 > 0) {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear - 1) + " IS " + to_string(diff3) + " DAY" + (diff3 == 1 ? "" : "S") + " AFTER";
            } else {
                result = to_string(reportMonth) + "/" + to_string(reportDay) + "/" + to_string(endYear - 1) + " IS " + to_string(-diff3) + " DAY" + (-diff3 == 1 ? "" : "S") + " PRIOR";
            }
        } else {
            result = "OUT OF RANGE";
        }

        cout << result << '\n';
    }

    return 0;
}
