#include <iostream>
#include <fstream> //讀檔用
using namespace std;
/*-----------------------------class-----------------------------*/
class Money
{
public:
    Money()
    { //建構式：名稱需與class相同/*前次作業遺留物*/
        MoneyCur = 0;
    }
    void login(string name)
    {
        /*讀檔*/
        string fileName = name + ".txt";
        ifstream f(fileName.c_str());
        if (f.good())
        { /*如果有找到一樣的檔名的話，就存取檔名內的數值進去MoneyCur*/
            cout << "有找到" << endl;
            fstream infile(fileName, fstream::in);
            //string name;
            ID = name;
            string cash;
            while (infile >> cash)
                {
                    int amount = atoi( cash.c_str() );
                    MoneyCur = amount;
                    cout << "eCash: 帳號開啟完成!" << endl;
                }
        }
        else
        {   /*如果沒有，則建立一個以輸入名稱為檔名的檔案*/
            cout << "帳號不存在，第一次使用！" << endl;
            
            fstream outfile(fileName, fstream::out);
            outfile << "0" << endl;
            outfile.close();
            ID = name;
            MoneyCur = 0;
            
            //cout << ID << endl <<  MoneyCur << endl;

        }

    } // class結束

    void logout(string name)
    {
        /*寫入檔案*/
        string fileName = name + ".txt";
        fstream outfile(fileName, fstream::out);
        outfile << MoneyCur << endl;
        outfile.close();
        cout << "eCash: 帳號登出，已存檔" << endl;
        cout << "謝謝，ByeBye!" << endl;
    }
    void store(int m)
    { // 2.儲值

        if (m < 0)
        {
            cout << "eCash: 請輸入大於0的金額" << endl;
        }
        else
        {
            MoneyCur += m;
            cout << "eCash: 您存了" << m << "元" << endl;
            // cout << "eCash: remaining " << MoneyCur << "." << endl;
        }
    }

    void pay(int m)
    {
        if (MoneyCur - m < 0)
        {
            cout << "eCash: 您的錢不夠" << endl;
        }
        else if (m < 0)
        {
            cout << "eCash: 請輸入大於0的金額" << endl;
        }
        else
        {
            MoneyCur -= m;
            cout << "eCash: 您花了" << m << "元" << endl;
            // cout << "eCash: You remaining "  << MoneyCur << "." << endl;
        }
    } //消費
    //~Money();  //解構式
    void display()
    {
        cout << "eCash: 您尚有" << MoneyCur << "元" << endl;
    } //顯示目前餘額 (將Money輸出於螢幕) 主程式
private:
    // string Name;  //沒有名稱
    int MoneyCur;
    string ID; /*待確認使用方法*/
};

/*-----------------------------主程式-----------------------------*/
int main(int argc, const char *argv[])
{
    string Name;
    cout << "=== 歡迎使用eCash ===" << endl;
    cout << "eCash: 請輸入您的帳號" << endl;
    Money ecash_pocket; /*前次作業遺留物-初始化*/
    cin >> Name;
    ecash_pocket.login(Name); //檢查與讀檔

    while (1)
    {

        int coin;
        char op;
        cout << Name << "您好,請選擇項目:" << endl; //顯示選單
        cout << "s: 儲值" << endl;
        cout << "p: 消費" << endl;
        cout << "d: 顯示餘額" << endl;
        cout << "q: 離開" << endl;
        cout << ">";
        cin >> op;
        cin.ignore();

        switch (op)
        { //選單
        case 's':
            cout << "請輸入儲存金額:" << endl;
            cin >> coin;
            ecash_pocket.store(coin);
            break;
        case 'p':
            cout << "請輸入消費金額:" << endl;
            cin >> coin;
            ecash_pocket.pay(coin);
            break;
        case 'd':
            ecash_pocket.display();
            break;
        case 'q':
            ecash_pocket.logout(Name);
            return 0;
            break;
        } // switch end
    }     // while end
    return 0;
}
