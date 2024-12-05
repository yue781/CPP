#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <Eigen/Dense>
// visual studio安装Eigen库 https://blog.csdn.net/weixin_45496950/article/details/135094807
using namespace std;
using namespace Eigen;

// 读取txt文件，提取经纬度和高度
void readData(const string& filename, vector<double>& altitudes) {
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        string lat_str, lon_str, alt_str;
        stringstream ss(line);
        string temp;
        
        while (getline(ss, temp, ',')) {
            if (temp.find("alt=") != string::npos) {
                alt_str = temp;
                break;
            }
        }

        size_t pos = alt_str.find("=");
        if (pos != string::npos) {
            double alt = stod(alt_str.substr(pos + 1));
            altitudes.push_back(alt);
        }
    }
}

// ARIMA模型拟合：差分处理，AR和MA部分的简单实现
class ARIMA {
public:
    ARIMA(int p, int d, int q) : p(p), d(d), q(q) {}

    // 差分处理
    vector<double> difference(const vector<double>& series, int d) {
        vector<double> diff_series = series;
        for (int i = 0; i < d; i++) {
            vector<double> temp(series.size() - 1);
            for (size_t j = 1; j < series.size(); j++) {
                temp[j - 1] = series[j] - series[j - 1];
            }
            diff_series = temp;
        }
        return diff_series;
    }

    // 计算自回归（AR）部分
    vector<double> fitAR(const vector<double>& series) {
        int n = series.size();
        vector<double> ar_params(p, 0);
        if (n <= p) return ar_params;

        MatrixXd X(n - p, p);
        VectorXd Y(n - p);

        // 构造X和Y矩阵
        for (int i = p; i < n; i++) {
            for (int j = 0; j < p; j++) {
                X(i - p, j) = series[i - j - 1];
            }
            Y(i - p) = series[i];
        }

        // 使用最小二乘法求解AR系数
        VectorXd ar_coefs = (X.transpose() * X).ldlt().solve(X.transpose() * Y);
        for (int i = 0; i < p; i++) {
            ar_params[i] = ar_coefs(i);
        }
        return ar_params;
    }

    // 简单实现MA（移动平均）部分
    vector<double> fitMA(const vector<double>& series) {
        vector<double> ma_params(q, 0);
        // 实现MA模型的拟合，可以类似处理
        // 在这里我们简化为返回零值，具体实现根据实际需求
        return ma_params;
    }

    // ARIMA模型拟合：差分 + AR部分 + MA部分
    vector<double> fit(const vector<double>& series) {
        // 差分
        vector<double> diff_series = difference(series, d);

        // AR部分
        vector<double> ar_params = fitAR(diff_series);

        // MA部分
        vector<double> ma_params = fitMA(diff_series);

        // 返回AR和MA参数作为模型的简化表示
        return ar_params;  // 这里只返回AR参数，MA部分需要进一步完善
    }

private:
    int p, d, q; // ARIMA(p, d, q)中的p、d、q
};

// 主函数
int main() {
    // 读取文件中的数据
    vector<double> altitudes;
    readData("data.txt", altitudes);  // 输入文件路径

    // 初始化ARIMA模型，假设p=1, d=1, q=1
    ARIMA arima(1, 1, 1);
    vector<double> model_params = arima.fit(altitudes);

    // 打印AR参数
    cout << "AR Parameters:" << endl;
    for (double param : model_params) {
        cout << param << " ";
    }
    cout << endl;

    // 可以继续实现模型预测部分
    // 例如：使用AR参数预测未来的altitude

    return 0;
}
