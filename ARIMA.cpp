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
// 在C++中，const string& filename 和 vector<double>& altitudes 是函数参数的声明。它们分别表示传递给函数的两个参数类型。具体解释如下：

// 1. const string& filename
// string：表示字符串类型，filename是一个字符串类型的变量，用来存储文件的路径或文件名。
// &：表示传递的是引用。在C++中，引用是一种允许函数访问原始变量的方式，而不需要复制整个对象。通过引用，函数能直接操作传入的变量，而不是该变量的副本。
    // 注意引用（&）和指针（*）的区别：
    // 不存在空引用，引用必须连接到一块合法的内存。
    // 一旦引用被初始化为一个对象，就不能被指向到另一个对象，指针可以在任何时候指向到另一个对象。
    // 引用必须在创建时被初始化，指针可以在任何时间被初始化。
// const：表示常量引用，意味着函数不会修改传入的filename变量的值。这样做的好处是：
// 避免复制：传递较大的对象时，使用引用可以避免不必要的复制开销。
// 保护数据：const保证函数不会改变传入的字符串内容。
// 综合来说，const string& filename是一个常量引用，意味着你传递给readData函数的是一个字符串（通常是文件的路径），并且函数不会修改这个字符串。

// 2. vector<double>& altitudes
// vector<double>：这是一个vector容器，可以存储多个double类型的元素。在这个例子中，altitudes是一个存储double值的vector，这些值代表读取的高度（alt）。
    // C++ 标准库（Standard Template Library, STL）是 C++ 的一个重要组成部分，它提供了一组通用的模板类和函数，用于处理数据集合。<vector> 是 STL 中的一个容器类，用于存储动态大小的数组。
    // <vector> 是一个序列容器，它允许用户在容器的末尾快速地添加或删除元素。与数组相比，<vector> 提供了更多的功能，如自动调整大小、随机访问等。
// &：同样表示传递的是引用，也就是说，readData函数会直接修改传入的altitudes容器的内容，而不是该容器的副本。
// 没有const：这意味着altitudes是一个可以被修改的容器，函数内部会直接向这个容器添加高度数据。
    
// 总结：
// const string& filename表示文件路径是一个常量引用，函数不会修改这个路径字符串。
// vector<double>& altitudes表示altitudes是一个引用，函数会在原始altitudes容器上进行操作，将读取到的高度数据存入这个容器。
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
