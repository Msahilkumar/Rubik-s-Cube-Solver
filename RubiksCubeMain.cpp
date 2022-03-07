#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>
#include "SourceCode.h"


using namespace std;
using namespace cv;



void display_cube() {
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
    cout << endl;
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 9;j++)cout << cube[i][j] << " ";cout << endl;
    }
}

char pixel_color(Scalar bgr) {
    if ((bgr[0] > 100 || bgr[0] < 3) && bgr[1]>=150) return 'r';
    else {
        if (bgr[0] >= 60 && bgr[0] <= 90 && bgr[1] >= 150) return 'g';
        if (bgr[0] > 23 && bgr[0] <= 60) return 'y';
        if (bgr[0] <= 23 && bgr[0] >= 3 ) return 'o';
        if (bgr[0] >= 0 && bgr[0] <= 170 && bgr[1] < 100) return 'w';
        if (bgr[0] >= 75 && bgr[0] <= 120) return 'b';
    }
    return 'u';
}

void make_matrix(Mat& img) {

    Mat mat_img = img;
    int stepSize = 65;
    int w = mat_img.size().width;
    int h = mat_img.size().height;


    for (int i = (w / 2) - 130; i < (w / 2) + 70; i += stepSize) {
        cv::line(mat_img, Point(i, (h / 2) - 130), Point(i, (h / 2) + 65), cv::Scalar(0, 255, 255), 3);
    }

    for (int i = (h / 2) - 130; i < (h / 2) + 70; i += stepSize) {

        cv::line(mat_img, Point((w / 2) - 130, i), Point((w / 2) + 65, i), cv::Scalar(0, 255, 255), 3);
    }

    vector<Rect> slices(9);


    Rect roi0(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[0] = roi0;
    Rect roi1(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[1] = roi1;
    Rect roi2(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[2] = roi2;
    Rect roi3(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[3] = roi3;
    Rect roi4(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[4] = roi4;
    Rect roi5(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[5] = roi5;
    Rect roi6(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[6] = roi6;
    Rect roi7(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[7] = roi7;
    Rect roi8(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[8] = roi8;

    for (int j = 0;j < 9;j++) {
        rectangle(mat_img, slices[j], Scalar(0, 255, 255));
    }
}

vector<char> get_color(Mat img) {
    Mat mat_img = img;
    vector<char> ans(9);
    int stepSize = 65;
    int w = mat_img.size().width;
    int h = mat_img.size().height;
    vector<Point> middle_points(9);
    vector<Rect> slices(9);
    vector<Scalar> avg_pixel(9);
    

    Rect roi0(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[0] = roi0;
    Rect roi1(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[1] = roi1;
    Rect roi2(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 3 / 2) - 16), 32, 32);slices[2] = roi2;
    Rect roi3(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[3] = roi3;
    Rect roi4(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[4] = roi4;
    Rect roi5(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) - (stepSize * 1 / 2) - 16), 32, 32);slices[5] = roi5;
    Rect roi6(((w / 2) - (stepSize * 3 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[6] = roi6;
    Rect roi7(((w / 2) - (stepSize * 1 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[7] = roi7;
    Rect roi8(((w / 2) + (stepSize * 1 / 2) - 16), ((h / 2) + (stepSize * 1 / 2) - 16), 32, 32);slices[8] = roi8;

    for (int _i = 0;_i < 9;_i++) {
        Scalar bgr = mean(img(slices[_i]));avg_pixel[_i] = bgr;
        cout << bgr[0] << " " << bgr[1] << " " << bgr[2] << endl;

    }


    for (int i = 0;i < 9;i++)ans[i] = pixel_color(avg_pixel[i]);
    return ans;
}

int main()
{
    Mat img;
    Mat img2;
    int c = 0;

    
    VideoCapture cap(0);
    cout << "show the upper face" << endl;
    cout << " press any key when you are ready" << endl;
    if (!cap.isOpened()) { cout << "error" << endl;return -1; }
    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }


    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[0] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);

    
    cout << "show the front face" << endl;
    cout << " press esc key when you are ready" << endl;

    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }
    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[2] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);


    cout << "show the bottom face" << endl;
    cout << " press esc key when you are ready" << endl;

    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }
    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[1] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);

    cout << "show the right face" << endl;
    cout << " press esc key when you are ready" << endl;

    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }
    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[3] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);

    cout << "show the back face" << endl;
    cout << " press esc key when you are ready" << endl;

    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }
    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[4] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);

    cout << "show the left face" << endl;
    cout << " press esc key when you are ready" << endl;

    while (1) {
        cap.read(img);
        make_matrix(img);
        imshow("imshow", img);
        if (waitKey(10) == 27) { img2 = img;break; }
    }
    cvtColor(img2, img2, COLOR_BGR2HSV);
    cube[5] = get_color(img2);
    imshow("njn", img2);
    waitKey(50);
    
    display_cube();
    int checcube = check_cube();
    if (checcube != -1) {
        if (checcube == 0)cout << "Not detected some colors" << endl;
        else cout <<"check corner number = "<< checcube << endl;
        return -1;
    }
    else cout << "cube is right" << endl;
    Solve_bottom_layer();
    cout << "completed till first layer" << endl << endl;
    solve_middle_layer();
    cout << "completed till second layer" << endl << endl;
    solve_all_top_yellow_face();
    cout << "made yello face at top" << endl << endl;
    solve_finally();
    cout << "Shoutig .......Solved...!" << endl;
    cout << endl << endl;
    cout << ans << endl;
    cout << executable_sequence.length() << endl;
    cout << executable_sequence << endl;
    string finans = MoveParsing();
    cout << finans.length() << endl;
    display_cube();

    return 0;
}