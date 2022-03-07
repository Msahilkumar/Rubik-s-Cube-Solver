//#include <bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<char>> cube(6, vector<char>(9));
string ans = "";
string executable_sequence = "";
void display() {
    cout << "____________Upper Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[0][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << "____________Bottom Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[1][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << "____________Front Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[2][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << "____________Right Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[3][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << "____________Back Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[4][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << "____________Left Face______________" << endl;
    for (int i = 0;i < 9;i++) {
        cout << cube[5][i] << " ";
        if ((i + 1) % 3 == 0)cout << endl;
    }
    cout << endl;



    cout << "        ";
    for (int i = 0;i < 9;i++) {
        cout << cube[0][i] << " ";
        if ((i + 1) % 3 == 0 && i != 8) { cout << endl;cout << "        "; }
    }
    cout << endl;cout << "-----------------------------" << endl;
    for (int j = 0;j < 3;j++)cout << cube[5][j] << " ";cout << "| ";
    for (int j = 0;j < 3;j++)cout << cube[2][j] << " ";cout << "| ";
    for (int j = 0;j < 3;j++)cout << cube[3][j] << " ";cout << "| ";
    for (int j = 0;j < 3;j++)cout << cube[4][j] << " ";cout << endl;
    for (int j = 3;j < 6;j++)cout << cube[5][j] << " ";cout << "| ";
    for (int j = 3;j < 6;j++)cout << cube[2][j] << " ";cout << "| ";
    for (int j = 3;j < 6;j++)cout << cube[3][j] << " ";cout << "| ";
    for (int j = 3;j < 6;j++)cout << cube[4][j] << " ";cout << endl;
    for (int j = 6;j < 9;j++)cout << cube[5][j] << " ";cout << "| ";
    for (int j = 6;j < 9;j++)cout << cube[2][j] << " ";cout << "| ";
    for (int j = 6;j < 9;j++)cout << cube[3][j] << " ";cout << "| ";
    for (int j = 6;j < 9;j++)cout << cube[4][j] << " ";cout << endl;
    cout << "-----------------------------" << endl;
    cout << "        ";
    for (int i = 0;i < 9;i++) {
        cout << cube[1][i] << " ";
        if ((i + 1) % 3 == 0 && i != 8) {
            cout << endl;
            cout << "        ";
        }
    }


}
void performAlgo(string algo) {
    executable_sequence += algo;
    for (int i = 0;i < algo.length();i++) {
        if (algo[i] == 'U') {
            char temp0 = cube[0][0], temp1 = cube[0][1], temp2 = cube[0][2], temp3 = cube[0][3], temp5 = cube[0][5], temp6 = cube[0][6], temp7 = cube[0][7], temp8 = cube[0][8];
            cube[0][0] = temp6;cube[0][1] = temp3;cube[0][2] = temp0;cube[0][3] = temp7;cube[0][5] = temp1;cube[0][6] = temp8;cube[0][7] = temp5;cube[0][8] = temp2;

            temp0 = cube[2][0], temp1 = cube[2][1], temp2 = cube[2][2];
            cube[2][0] = cube[3][0];
            cube[2][1] = cube[3][1];
            cube[2][2] = cube[3][2];
            cube[3][0] = cube[4][0];
            cube[3][1] = cube[4][1];
            cube[3][2] = cube[4][2];
            cube[4][0] = cube[5][0];
            cube[4][1] = cube[5][1];
            cube[4][2] = cube[5][2];
            cube[5][0] = temp0;cube[5][1] = temp1;cube[5][2] = temp2;
            // cout<<"Succesfully Performed Move U"<<endl;

        }
        else if (algo[i] == 'u') {
            char temp0 = cube[0][0], temp1 = cube[0][1], temp2 = cube[0][2], temp3 = cube[0][3], temp5 = cube[0][5], temp6 = cube[0][6], temp7 = cube[0][7], temp8 = cube[0][8];
            cube[0][0] = temp2;cube[0][1] = temp5;cube[0][2] = temp8;cube[0][3] = temp1;cube[0][5] = temp7;cube[0][6] = temp0;cube[0][7] = temp3;cube[0][8] = temp6;

            temp0 = cube[2][0], temp1 = cube[2][1], temp2 = cube[2][2];
            cube[2][0] = cube[5][0];
            cube[2][1] = cube[5][1];
            cube[2][2] = cube[5][2];
            cube[5][0] = cube[4][0];
            cube[5][1] = cube[4][1];
            cube[5][2] = cube[4][2];
            cube[4][0] = cube[3][0];
            cube[4][1] = cube[3][1];
            cube[4][2] = cube[3][2];
            cube[3][0] = temp0;cube[3][1] = temp1;cube[3][2] = temp2;
            // cout<<"Succesfully Performed Move u"<<endl;

        }
        else if (algo[i] == 'F') {
            char temp0 = cube[2][0], temp1 = cube[2][1], temp2 = cube[2][2], temp3 = cube[2][3], temp5 = cube[2][5], temp6 = cube[2][6], temp7 = cube[2][7], temp8 = cube[2][8];
            cube[2][0] = temp6;cube[2][1] = temp3;cube[2][2] = temp0;cube[2][3] = temp7;cube[2][5] = temp1;cube[2][6] = temp8;cube[2][7] = temp5;cube[2][8] = temp2;


            temp0 = cube[0][6], temp1 = cube[0][7], temp2 = cube[0][8];
            cube[0][6] = cube[5][8];
            cube[0][7] = cube[5][5];
            cube[0][8] = cube[5][2];
            cube[5][8] = cube[1][2];
            cube[5][5] = cube[1][1];
            cube[5][2] = cube[1][0];
            cube[1][2] = cube[3][0];
            cube[1][1] = cube[3][3];
            cube[1][0] = cube[3][6];
            cube[3][0] = temp0;cube[3][3] = temp1;cube[3][6] = temp2;
            // cout<<"Succesfully Performed Move F"<<endl;

        }
        else if (algo[i] == 'f') {
            char temp0 = cube[2][0], temp1 = cube[2][1], temp2 = cube[2][2], temp3 = cube[2][3], temp5 = cube[2][5], temp6 = cube[2][6], temp7 = cube[2][7], temp8 = cube[2][8];
            cube[2][0] = temp2;cube[2][1] = temp5;cube[2][2] = temp8;cube[2][3] = temp1;cube[2][5] = temp7;cube[2][6] = temp0;cube[2][7] = temp3;cube[2][8] = temp6;

            temp0 = cube[0][6], temp1 = cube[0][7], temp2 = cube[0][8];
            cube[0][6] = cube[3][0];
            cube[0][7] = cube[3][3];
            cube[0][8] = cube[3][6];
            cube[3][0] = cube[1][2];
            cube[3][3] = cube[1][1];
            cube[3][6] = cube[1][0];
            cube[1][2] = cube[5][8];
            cube[1][1] = cube[5][5];
            cube[1][0] = cube[5][2];
            cube[5][8] = temp0;cube[5][5] = temp1;cube[5][2] = temp2;
            // cout<<"Succesfully Performed Move f"<<endl;

        }
        else if (algo[i] == 'R') {
            char temp0 = cube[3][0], temp1 = cube[3][1], temp2 = cube[3][2], temp3 = cube[3][3], temp5 = cube[3][5], temp6 = cube[3][6], temp7 = cube[3][7], temp8 = cube[3][8];
            cube[3][0] = temp6;cube[3][1] = temp3;cube[3][2] = temp0;cube[3][3] = temp7;cube[3][5] = temp1;cube[3][6] = temp8;cube[3][7] = temp5;cube[3][8] = temp2;

            temp0 = cube[0][8], temp1 = cube[0][5], temp2 = cube[0][2];
            cube[0][8] = cube[2][8];
            cube[0][5] = cube[2][5];
            cube[0][2] = cube[2][2];
            cube[2][8] = cube[1][8];
            cube[2][5] = cube[1][5];
            cube[2][2] = cube[1][2];
            cube[1][8] = cube[4][0];
            cube[1][5] = cube[4][3];
            cube[1][2] = cube[4][6];
            cube[4][0] = temp0;cube[4][3] = temp1;cube[4][6] = temp2;
            // cout<<"Succesfully Performed Move R"<<endl;

        }
        else if (algo[i] == 'r') {
            char temp0 = cube[3][0], temp1 = cube[3][1], temp2 = cube[3][2], temp3 = cube[3][3], temp5 = cube[3][5], temp6 = cube[3][6], temp7 = cube[3][7], temp8 = cube[3][8];
            cube[3][0] = temp2;cube[3][1] = temp5;cube[3][2] = temp8;cube[3][3] = temp1;cube[3][5] = temp7;cube[3][6] = temp0;cube[3][7] = temp3;cube[3][8] = temp6;

            temp0 = cube[0][8], temp1 = cube[0][5], temp2 = cube[0][2];
            cube[0][8] = cube[4][0];
            cube[0][5] = cube[4][3];
            cube[0][2] = cube[4][6];
            cube[4][0] = cube[1][8];
            cube[4][3] = cube[1][5];
            cube[4][6] = cube[1][2];
            cube[1][8] = cube[2][8];
            cube[1][5] = cube[2][5];
            cube[1][2] = cube[2][2];
            cube[2][8] = temp0;cube[2][5] = temp1;cube[2][2] = temp2;
            // cout<<"Succesfully Performed Move r"<<endl;

        }
        else if (algo[i] == 'L') {
            char temp0 = cube[5][0], temp1 = cube[5][1], temp2 = cube[5][2], temp3 = cube[5][3], temp5 = cube[5][5], temp6 = cube[5][6], temp7 = cube[5][7], temp8 = cube[5][8];
            cube[5][0] = temp6;cube[5][1] = temp3;cube[5][2] = temp0;cube[5][3] = temp7;cube[5][5] = temp1;cube[5][6] = temp8;cube[5][7] = temp5;cube[5][8] = temp2;


            temp0 = cube[0][0], temp1 = cube[0][3], temp2 = cube[0][6];
            cube[0][0] = cube[4][8];
            cube[0][3] = cube[4][5];
            cube[0][6] = cube[4][2];
            cube[4][8] = cube[1][0];
            cube[4][5] = cube[1][3];
            cube[4][2] = cube[1][6];
            cube[1][0] = cube[2][0];
            cube[1][3] = cube[2][3];
            cube[1][6] = cube[2][6];
            cube[2][0] = temp0;cube[2][3] = temp1;cube[2][6] = temp2;
            // cout<<"Succesfully Performed Move L"<<endl;

        }
        else if (algo[i] == 'l') {
            char temp0 = cube[5][0], temp1 = cube[5][1], temp2 = cube[5][2], temp3 = cube[5][3], temp5 = cube[5][5], temp6 = cube[5][6], temp7 = cube[5][7], temp8 = cube[5][8];
            cube[5][0] = temp2;cube[5][1] = temp5;cube[5][2] = temp8;cube[5][3] = temp1;cube[5][5] = temp7;cube[5][6] = temp0;cube[5][7] = temp3;cube[5][8] = temp6;

            temp0 = cube[0][0], temp1 = cube[0][3], temp2 = cube[0][6];
            cube[0][0] = cube[2][0];
            cube[0][3] = cube[2][3];
            cube[0][6] = cube[2][6];
            cube[2][0] = cube[1][0];
            cube[2][3] = cube[1][3];
            cube[2][6] = cube[1][6];
            cube[1][0] = cube[4][8];
            cube[1][3] = cube[4][5];
            cube[1][6] = cube[4][2];
            cube[4][8] = temp0;cube[4][5] = temp1;cube[4][2] = temp2;
            // cout<<"Succesfully Performed Move l"<<endl;

        }
        else if (algo[i] == 'B') {
            char temp0 = cube[4][0], temp1 = cube[4][1], temp2 = cube[4][2], temp3 = cube[4][3], temp5 = cube[4][5], temp6 = cube[4][6], temp7 = cube[4][7], temp8 = cube[4][8];
            cube[4][0] = temp6;cube[4][1] = temp3;cube[4][2] = temp0;cube[4][3] = temp7;cube[4][5] = temp1;cube[4][6] = temp8;cube[4][7] = temp5;cube[4][8] = temp2;

            temp0 = cube[0][2], temp1 = cube[0][1], temp2 = cube[0][0];
            cube[0][2] = cube[3][8];
            cube[0][1] = cube[3][5];
            cube[0][0] = cube[3][2];
            cube[3][8] = cube[1][6];
            cube[3][5] = cube[1][7];
            cube[3][2] = cube[1][8];
            cube[1][6] = cube[5][0];
            cube[1][7] = cube[5][3];
            cube[1][8] = cube[5][6];
            cube[5][0] = temp0;cube[5][3] = temp1;cube[5][6] = temp2;
            // cout<<"Succesfully Performed Move B"<<endl;

        }
        else if (algo[i] == 'b') {
            char temp0 = cube[4][0], temp1 = cube[4][1], temp2 = cube[4][2], temp3 = cube[4][3], temp5 = cube[4][5], temp6 = cube[4][6], temp7 = cube[4][7], temp8 = cube[4][8];
            cube[4][0] = temp2;cube[4][1] = temp5;cube[4][2] = temp8;cube[4][3] = temp1;cube[4][5] = temp7;cube[4][6] = temp0;cube[4][7] = temp3;cube[4][8] = temp6;

            temp0 = cube[0][2], temp1 = cube[0][1], temp2 = cube[0][0];
            cube[0][2] = cube[5][0];
            cube[0][1] = cube[5][3];
            cube[0][0] = cube[5][6];
            cube[5][0] = cube[1][6];
            cube[5][3] = cube[1][7];
            cube[5][6] = cube[1][8];
            cube[1][6] = cube[3][8];
            cube[1][7] = cube[3][5];
            cube[1][8] = cube[3][2];
            cube[3][8] = temp0;cube[3][5] = temp1;cube[3][2] = temp2;
            // cout<<"Succesfully Performed Move b"<<endl;
        }
    }
}

char colour(int i) {
    if (i == 2) return 'g';else if (i == 3) return 'o';if (i == 4) return 'b';else if (i == 5) return 'r';
}
bool is_first_layer_solved() {
    for (int i = 0;i < 9;i++) if (cube[1][i] != 'w') return false;
    for (int i = 2;i < 6;i++) {
        char ch = colour(i);
        if (cube[i][6] != ch || cube[i][7] != ch || cube[i][8] != ch)return false;
    }
    return true;
}
bool check_top_yellow() {
    return cube[0][1] == 'w' && cube[0][3] == 'w' && cube[0][5] == 'w' && cube[0][7] == 'w';
}
void upper_layer_white_solve(int faceNo) {
    string face[6] = { "","","F","R","B","L" };
    performAlgo(face[faceNo]);ans += face[faceNo];
    if (faceNo == 2) {
        while (cube[0][5] == 'w') { performAlgo("U");ans += 'U'; }
        performAlgo("R");ans += "R";
    }
    else if (faceNo == 3) {
        while (cube[0][1] == 'w') { performAlgo("U");ans += 'U'; }
        performAlgo("B");ans += "B";
    }
    else if (faceNo == 4) {
        while (cube[0][3] == 'w') { performAlgo("U");ans += 'U'; }
        performAlgo("L");ans += 'L';
    }
    else {
        while (cube[0][7] == 'w') { performAlgo("U");ans += 'U'; }
        performAlgo("F");ans += "F";
    }
}
void solve_top_yellow_centre() {
    while (!check_top_yellow()) {
        if (cube[2][3] == 'w') {
            while (cube[0][3] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("l");ans += 'l';
        }
        else if (cube[2][5] == 'w') {
            while (cube[0][5] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("R");ans += 'R';
        }
        else if (cube[5][5] == 'w') {
            while (cube[0][7] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("F");ans += 'F';
        }
        else if (cube[3][3] == 'w') {
            while (cube[0][7] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("f");ans += 'f';
        }
        else if (cube[1][3] == 'w') {
            while (cube[0][3] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("ll");ans += "ll";
        }
        else if (cube[1][5] == 'w') {
            while (cube[0][5] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("RR");ans += "RR";
        }
        else if (cube[1][1] == 'w') {
            while (cube[0][7] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("FF");ans += "FF";
        }
        else if (cube[1][7] == 'w') {
            while (cube[0][1] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("BB");ans += "BB";
        }
        else if (cube[4][5] == 'w') {
            while (cube[0][3] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("L");ans += "L";
        }
        else if (cube[4][3] == 'w') {
            while (cube[0][5] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("r");ans += "r";
        }
        else if (cube[5][3] == 'w') {
            while (cube[0][1] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("b");ans += 'b';
        }
        else if (cube[3][5] == 'w') {
            while (cube[0][1] == 'w') { performAlgo("U");ans += 'U'; }
            performAlgo("B");ans += 'B';
        }
        else if (cube[2][1] == 'w') {
            upper_layer_white_solve(2);
        }
        else if (cube[3][1] == 'w') {
            upper_layer_white_solve(3);
        }
        else if (cube[4][1] == 'w') {
            upper_layer_white_solve(4);
        }
        else if (cube[5][1] == 'w') {
            upper_layer_white_solve(5);
        }
        else if (cube[2][7] == 'w') {
            performAlgo("FF");ans += "FF";upper_layer_white_solve(2);
        }
        else if (cube[3][7] == 'w') {
            performAlgo("RR");ans += "RR";upper_layer_white_solve(3);
        }
        else if (cube[4][7] == 'w') {
            performAlgo("BB");ans += "BB";upper_layer_white_solve(4);
        }
        else if (cube[5][7] == 'w') {
            performAlgo("LL");ans += "LL";upper_layer_white_solve(5);
        }
    }
}
void make_white_cross() {
    while (cube[2][1] != 'g' || cube[0][7] != 'w') { performAlgo("U");ans += 'U'; }
    performAlgo("FF");ans += "FF";
    while (cube[3][1] != 'o' || cube[0][5] != 'w') { performAlgo("U");ans += 'U'; }
    performAlgo("RR");ans += "RR";
    while (cube[4][1] != 'b' || cube[0][1] != 'w') { performAlgo("U");ans += 'U'; }
    performAlgo("BB");ans += "BB";
    while (cube[5][1] != 'r' || cube[0][3] != 'w') { performAlgo("U");ans += 'U'; }
    performAlgo("LL");ans += "LL";
}
void rightAlgo(int faceNo) {
    string ar[6] = { "","","RUr","BUb","LUl","FUf" };
    performAlgo(ar[faceNo]);ans += ('-' + ar[faceNo] + '-');
}
void leftAlgo(int faceNo) {
    string ar[6] = { "","","luL","fuF","ruR","buB" };
    performAlgo(ar[faceNo]);ans += ('-' + ar[faceNo] + '-');
}
bool is_there_white_in_top_layer() {
    return cube[2][0] == 'w' || cube[2][2] == 'w' || cube[3][0] == 'w' || cube[3][2] == 'w' || cube[4][0] == 'w' || cube[4][2] == 'w' || cube[5][0] == 'w' || cube[5][2] == 'w';
}
bool is_there_white_in_bottom_layer() {
    return cube[2][6] == 'w' || cube[2][8] == 'w' || cube[3][6] == 'w' || cube[3][8] == 'w' || cube[4][6] == 'w' || cube[4][8] == 'w' || cube[5][6] == 'w' || cube[5][8] == 'w';
}
void solve_white_in_top_layer_front_face() {
    if (cube[2][0] == 'w') {
        int i = 5;
        while (cube[i][4] != cube[i][2] && i >= 2) { performAlgo("U");ans += "U";i--; }
        rightAlgo(i);
    }
    if (cube[2][2] == 'w') {
        int i = 3;
        while (cube[i][4] != cube[i][0] && i >= 2 && i <= 5) { performAlgo("u");ans += "u";i++;if (i == 6) i = 2; }
        leftAlgo(i);
    }
}
void solve_white_in_top_layer_at_any_position() {
    while (is_there_white_in_top_layer()) {
        solve_white_in_top_layer_front_face();
        if (cube[3][0] == 'w' || cube[3][2] == 'w') { performAlgo("U");ans += "U";solve_white_in_top_layer_front_face(); }
        if (cube[5][0] == 'w' || cube[5][2] == 'w') { performAlgo("u");ans += "u";solve_white_in_top_layer_front_face(); }
        if (cube[4][0] == 'w' || cube[4][2] == 'w') { performAlgo("UU");ans += "UU";solve_white_in_top_layer_front_face(); }
    }
}
void solve_white_in_bottom_layer() {
    while (is_there_white_in_bottom_layer()) {
        if (cube[2][6] == 'w') { rightAlgo(5);solve_white_in_top_layer_at_any_position(); }
        else if (cube[2][8] == 'w') { leftAlgo(3);solve_white_in_top_layer_at_any_position(); }
        else if (cube[3][6] == 'w') { rightAlgo(2);solve_white_in_top_layer_at_any_position(); }
        else if (cube[3][8] == 'w') { leftAlgo(4);solve_white_in_top_layer_at_any_position(); }
        else if (cube[4][6] == 'w') { rightAlgo(3);solve_white_in_top_layer_at_any_position(); }
        else if (cube[4][8] == 'w') { leftAlgo(5);solve_white_in_top_layer_at_any_position(); }
        else if (cube[5][6] == 'w') { rightAlgo(4);solve_white_in_top_layer_at_any_position(); }
        else if (cube[5][8] == 'w') { leftAlgo(2);solve_white_in_top_layer_at_any_position(); }
    }
}
int upper_white_count() {
    int ans = 0;
    for (int i = 0;i < 9;i++) { if ((i == 0 || i == 2 || i == 6 || i == 8) && cube[0][i] == 'w')ans++; }
    return ans;
}
void clear_top_bottom_layer() {
    while (is_there_white_in_top_layer() || is_there_white_in_bottom_layer()) {
        solve_white_in_top_layer_at_any_position();
        solve_white_in_bottom_layer();
    }
}
char colo(int i) {
    if (i == 2) return 'g';else if (i == 3) return 'o';else if (i == 4) return 'b';else if (i == 5) return 'r';
}
void Solve_bottom_layer() {
    if (is_first_layer_solved()) return;
    solve_top_yellow_centre();
    make_white_cross();
    clear_top_bottom_layer();
    while (upper_white_count() > 0) {
        if (cube[1][0] != 'w') { while (cube[0][6] != 'w') { performAlgo("U");ans += 'U'; }leftAlgo(2);clear_top_bottom_layer(); }
        else if (cube[1][2] != 'w') { while (cube[0][8] != 'w') { performAlgo("U");ans += 'U'; }leftAlgo(3);clear_top_bottom_layer(); }
        else if (cube[1][6] != 'w') { while (cube[0][0] != 'w') { performAlgo("U");ans += 'U'; }leftAlgo(5);clear_top_bottom_layer(); }
        else if (cube[1][8] != 'w') { while (cube[0][2] != 'w') { performAlgo("U");ans += 'U'; }leftAlgo(4);clear_top_bottom_layer(); }
    }
    if (!is_first_layer_solved()) {
        for (int i = 2;i < 6;i++) {
            if (cube[i][6] != colo(i)) { leftAlgo(i);clear_top_bottom_layer(); }
            if (cube[i][8] != colo(i)) { rightAlgo(i);clear_top_bottom_layer(); }
        }
    }
}

int top_pos_i(int i) {
    if (i == 2)return 7;else if (i == 3) return 5;else if (i == 4)return 1;else if (i == 5)return 3;
}
bool is_there_any_without_yellow_in_top_cross() {
    for (int i = 2;i < 6;i++)  if (cube[0][top_pos_i(i)] != 'y' && cube[i][1] != 'y') return true;
    return false;
}
void rightAlgorithm_middle(int i) {
    string ar[6] = { "","","URUrufuF","UBUburuR","ULUlubuB","UFUfuluL" };
    performAlgo(ar[i]);ans += ('-' + ar[i] + '-');
}
void leftalgorithm_middle(int i) {
    string ar[6] = { "","","uluLUFUf","ufuFURUr","uruRUBUb","ubuBULUl" };
    performAlgo(ar[i]);ans += ('-' + ar[i] + '-');
}
int ready_for_leftright() {
    for (int i = 2;i < 6;i++) if (cube[i][1] == cube[i][4] && cube[0][top_pos_i(i)] != 'y') return i;
    return -1;
}
void clear_middle() {
    while (is_there_any_without_yellow_in_top_cross()) {
        for (int i = 2;i < 6;i++) {
            if (ready_for_leftright() != -1) break;
            performAlgo("U");ans += 'U';
        }
        int i = ready_for_leftright();
        int j;if (i + 1 <= 5) j = i + 1;else j = 2;
        if (cube[j][4] != cube[0][top_pos_i(i)]) leftalgorithm_middle(i);
        else if (cube[j][4] == cube[0][top_pos_i(i)]) rightAlgorithm_middle(i);
    }
}
bool middle_layer_solved() {
    return (cube[2][3] == 'g' && cube[2][5] == 'g' && cube[3][3] == 'o' && cube[3][5] == 'o' && cube[4][3] == 'b' && cube[4][5] == 'b' && cube[5][3] == 'r' && cube[5][5] == 'r');
}
void solve_middle_layer() {
    if (middle_layer_solved()) return;
    clear_middle();
    if (!middle_layer_solved()) {
        int i = 2;
        while (i < 6) {
            if (cube[i][3] != cube[i][4]) break;
            if (cube[i][5] != cube[i][4]) break;
            i++;
        }
        if (cube[i][3] != cube[i][4])leftalgorithm_middle(i);
        else if (cube[i][5] != cube[i][4]) rightAlgorithm_middle(i);
        clear_middle();
    }
    if (!middle_layer_solved()) {
        int i = 2;
        while (i < 6) {
            if (cube[i][3] != cube[i][4]) break;
            if (cube[i][5] != cube[i][4]) break;
            i++;
        }
        if (cube[i][3] != cube[i][4])leftalgorithm_middle(i);
        else if (cube[i][5] != cube[i][4]) rightAlgorithm_middle(i);
        clear_middle();
    }
}
int top_ege_yellow_count() {
    int ans = 0;if (cube[0][1] == 'y')ans++;if (cube[0][3] == 'y')ans++;if (cube[0][5] == 'y')ans++;if (cube[0][7] == 'y')ans++;
    return ans;
}
bool is_line() {
    return ((cube[0][3] == 'y' && cube[0][5] == 'y') || (cube[0][7] == 'y' && cube[0][1] == 'y'));
}
void make_top_yello_cross() {
    while (top_ege_yellow_count() != 4) {
        if (top_ege_yellow_count() == 0) { performAlgo("FURurf");ans += "-FURurf-"; }
        else if (top_ege_yellow_count() == 1) { performAlgo("FURurf");ans += "-FURurf-"; }
        else if (top_ege_yellow_count() == 2) {
            if (is_line()) { performAlgo("FURurf");ans += "-FURurf-"; }
            else {
                while (cube[0][3] != 'y' || cube[0][1] != 'y') { performAlgo("U");ans += 'U'; }
                performAlgo("FURurf");ans += "-FURurf-";
            }
        }
        else if (top_ege_yellow_count() == 3) {
            while (cube[0][7] != 'y') { performAlgo("U");ans += 'U'; }
            performAlgo("FURurf");ans += "-FURurf-";
        }
    }
}
int top_corner_yellow_count() {
    int cnt = 0;
    for (int i = 0;i < 9;i++) { if ((i == 0 || i == 2 || i == 6 || i == 8) && cube[0][i] == 'y')cnt++; }
    return cnt;
}
bool yellow_face_solved() {
    for (int i = 0;i < 9;i++) if (cube[0][i] != 'y') return false;
    return true;
}
void solve_all_top_yellow_face() {
    if (yellow_face_solved()) return;
    make_top_yello_cross();
    while (top_corner_yellow_count() != 4) {
        if (top_corner_yellow_count() == 0 || top_corner_yellow_count() == 2) {
            while (cube[5][2] != 'y') { performAlgo("U");ans += 'U'; }
            performAlgo("RUrURUUr");ans += "-RUrURUUr-";
        }
        else if (top_corner_yellow_count() == 1) {
            while (cube[0][6] != 'y') { performAlgo("U");ans += 'U'; }
            performAlgo("RUrURUUr");ans += "-RUrURUUr-";
        }
    }
}

bool is_there_two_same() {
    for (int i = 2;i < 6;i++) { if (cube[i][0] == cube[i][2])return true; }
    return false;
}
bool is_there_three_same() {
    for (int i = 2;i < 6;i++) { if ((cube[i][0] == cube[i][1]) && (cube[i][1] == cube[i][2]))return true; }
    return false;
}
void perform_F_2_algo(int i) {

    string ar[6] = { "","","BBURlBBrLUBB","LLUfBLLbFULL","FFUrLFFlRUFF","RRUbFRRfBURR" };
    performAlgo(ar[i]);ans += ('-' + ar[i] + '-');
}
bool is_face_solved(int i) {
    for (int j = 1;j < 9;j++) { if (cube[i][j] != cube[i][j - 1])return false; }
    return true;
}
bool solved() {
    for (int i = 0;i < 6;i++) {
        if (!is_face_solved(i)) return false;
    }
    return true;
}
int is_any_face_solved() {
    for (int i = 2;i < 6;i++) {
        if (is_face_solved(i)) return i;
    }
    return -1;
}
bool is_all_pairs_same() {
    for (int i = 2;i < 6;i++) { if (cube[i][0] != cube[i][2]) return false; }
    return true;
}
void solve_finally() {
    if (solved()) return;
    while (!is_there_two_same()) {
        performAlgo("lURuLUUrURUUr");ans += "-lURuLUUrURUUr-";
    }
    if (is_there_two_same() && !is_all_pairs_same()) {
        while (cube[5][0] != cube[5][2]) { performAlgo("U");ans += 'U'; }
        performAlgo("lURuLUUrURUUr");ans += "-lURuLUUrURUUr-";
    }
    if (!is_there_three_same()) {
        perform_F_2_algo(4);
    }
    if (is_there_three_same()) {
        for (int i = 2;i < 6;i++) {
            if (is_any_face_solved() != -1) break;
            performAlgo("U");ans += 'U';
        }
    }
    if (solved()) return;
    int solved_face = is_any_face_solved();
    perform_F_2_algo(solved_face);
    if (!solved()) perform_F_2_algo(solved_face);
    if (!solved()) perform_F_2_algo(solved_face);
    if (!solved()) cout << "Algorithm failed..!" << endl;
}
bool check(int l, int r, string& moves) {
    if ((moves[l] <= 'Z' && moves[l] >= 'A') && moves[l] == moves[r] - 32) return true;
    else if ((moves[l] <= 'z' && moves[l] >= 'a') && moves[l] == moves[r] + 32) return true;
    return false;
}
string MoveParsing() {
    string finalans2 = "", finalans1 = "", newans = "";
    int n = executable_sequence.length();
    int t = 0;
    while (t < n) {
        if (t + 2 < n && (executable_sequence[t] == executable_sequence[t + 1] && executable_sequence[t + 1] == executable_sequence[t + 2])) { newans += ((executable_sequence[t] <= 'Z' && executable_sequence[t] >= 'A') ? executable_sequence[t] + 32 : executable_sequence[t] - 32);t = t + 3; }
        else { newans += executable_sequence[t];t++; }
    }
    t = 0;
    while (t < newans.length()) {
        if (t + 1 < newans.length() && check(t, t + 1, newans)) { t = t + 2;continue; }
        else { finalans1 += newans[t];t++; }
    }
    t = 0;
    while (t < finalans1.length()) {
        if (t + 1 < finalans1.length() && check(t, t + 1, finalans1)) { t = t + 2;continue; }
        else { finalans2 += finalans1[t];t++; }
    }
    return finalans2;
}
int check_cube() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 9;j++) {
            if (cube[i][j] == 'u') return 0;
        }
    }
    if (cube[0][8] == cube[2][2] || cube[2][2] == cube[3][0] || cube[0][8] == cube[3][0]) return 1;
    if (cube[0][6] == cube[2][0] || cube[2][0] == cube[5][2] || cube[0][6] == cube[5][2]) return 2;
    if (cube[0][0] == cube[5][0] || cube[5][0] == cube[4][2] || cube[0][0] == cube[4][2]) return 3;
    if (cube[0][2] == cube[4][0] || cube[4][0] == cube[3][2] || cube[0][2] == cube[3][2]) return 4;
    if (cube[1][0] == cube[2][6] || cube[2][6] == cube[5][8] || cube[1][0] == cube[5][8]) return 5;
    if (cube[1][2] == cube[2][8] || cube[2][8] == cube[3][6] || cube[1][2] == cube[3][6]) return 6;
    if (cube[1][6] == cube[5][6] || cube[5][6] == cube[4][8] || cube[1][6] == cube[4][8]) return 7;
    if (cube[1][8] == cube[4][6] || cube[4][6] == cube[3][8] || cube[1][8] == cube[3][8]) return 8;
    return -1;
}