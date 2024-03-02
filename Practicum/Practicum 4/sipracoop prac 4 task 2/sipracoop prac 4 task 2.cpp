//Задача 2
#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

const size_t EXAMSIZE = 3;
const size_t QSIZE = 100;
const size_t PASSSIZE = 10;

class Task {
    //условие (низ с фиксирана дължина)
    char taskQuestion[QSIZE]="";
    //правилен отговор (символ)
    char symbol='-';
    //брой точки, които носи задачата
    unsigned points=0;
    //парола, чрез която може да се редактира задачата
    char password[PASSSIZE]="";
    //За да правят тези промени обаче, трябва да са въвели правилна парола.
    bool IsPasswordValid(const char* password) const {
        return strcmp(this->password, password) == 0;
    }
    //избираем отговор (а,б,в,г)
    bool isSymbolValid(char ch) {
        return ch >= 'a' && ch <= 'd';
    }
public:
    //този конструстор е за да мога да създам масив от задачи
    Task() {

    }
    //да създават задача
    Task(const char* password, const char* taskQ, unsigned points, char symbol) {
            setPassword(password);
            setTaskQuestion(taskQ,password);
            setPoints(points,password);
            setSymbol(symbol,password);
    }
    //във всеки момент да могат да променят условието
    void setTaskQuestion(const char* task,const char* password) {
        if (IsPasswordValid(password)) {
            strcpy(this->taskQuestion, task);
        }
    }
    //да променят правилния отговор
    void setSymbol(char ch,const char* password) {
        if (IsPasswordValid(password) && isSymbolValid(ch)) {
            this->symbol = ch;
        }
    }
    //да променят броя точки
    void setPoints(unsigned points,const char*password) {
        if (IsPasswordValid(password)) {
            this->points = points;
        }
    }
    void setPassword(const char* password) {
        strcpy(this->password, password);
    }
    const char* getTaskQuestion() const {
        return taskQuestion;
    }
    const char* get$Password() const {
        return password;
    }
    char getSymbol() const {
        return symbol;
    }
    unsigned getPoints() const {
        return points;
    }
};
//клас Контролно, който съдържа фиксиран брой задачи
class Exam {
    Task tasks[EXAMSIZE];
public:
    Task* getTasks() {
        return tasks;
    }
    Task getCurrentTask(unsigned i) const {
        return tasks[i];
    }
    void setTasks(const Task* tasks) {
        for (size_t i = 0; i < EXAMSIZE; i++)
        {
            this->tasks[i].setPassword(tasks[i].get$Password());
            this->tasks[i].setPoints(tasks[i].getPoints(), tasks[i].get$Password());
            this->tasks[i].setSymbol(tasks[i].getSymbol(), tasks[i].get$Password());
            this->tasks[i].setTaskQuestion(tasks[i].getTaskQuestion(), tasks[i].get$Password());
        }
    }
    void printExam() {
        for (size_t i = 0; i < EXAMSIZE; i++)
        {
            std::cout << tasks[i].getPoints() << " " << tasks[i].getSymbol() << " " << tasks[i].getTaskQuestion()<<std::endl;
        }
    }
    //да се изчислява максималният брой точки за цялото контролно
    unsigned CalculatePoints(){
        unsigned sum = 0;
        for (size_t i = 0; i < EXAMSIZE; i++)
        {
            sum += tasks[i].getPoints();
        }
        return sum;
    }
};
int getFileSize(std::ifstream& file)
{
    int currentPos = file.tellg();
    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.seekg(currentPos);
    return fileSize;
}
//да се чете контролно със задачи от двоичен файл
void readExam(std::ifstream& readStream,Exam& exam) {
    int filesSize = getFileSize(readStream);
    //Task* tasks=new Task[EXAMSIZE];
    readStream.read((char*)&exam, filesSize);
    //exam.setTasks(tasks);
    //delete[] tasks;
}
//да се записва контролно в двоичен файл
void writeExam(std::ofstream& ofs) {
    Exam newExam;
    Task* tasks = new Task[EXAMSIZE];
    char question[QSIZE];
    char symbol;
    unsigned points;
    char password[PASSSIZE];
    for (size_t i = 0; i < EXAMSIZE; i++)
    {
        std::cout << "What will be the task?" << std::endl;
        std::cin.getline(question,QSIZE);
        std::cout << "What will be the password?" << std::endl;
        std::cin >> password;
        std::cout << "Which will be the right answer?" << std::endl;
        std::cin >> symbol;
        std::cout << "What will be the points you get?" << std::endl;
        std::cin >> points;
        std::cin.ignore();
        tasks[i].setPassword(password);
        tasks[i].setPoints(points,password);
        tasks[i].setSymbol(symbol,password);
        tasks[i].setTaskQuestion(question,password);
    }
    newExam.setTasks(tasks);
    ofs.write((const char*)&newExam, sizeof(newExam));
    delete[] tasks;
}
int main()
{
    /*Task tk("1234", "Kolko e 5*4?", 20, 'a');
    std::ofstream writeFile("tasks.dat", std::ios::out | std::ios::binary);
    writeFile.write((const char*)&tk, sizeof(tk));
    writeFile.close();
    Task tk2;
    readFile.read((char*)&tk2,sizeof(Task));
    std::cout << tk2.getPoints()<<" "<<tk2.getSymbol()<<" "<<tk2.getTaskQuestion();*/
    //std::cout << exam.CalculatePoints();*/
    //std::ofstream writeFile("tasks.dat", std::ios::out | std::ios::binary);
    //writeExam(writeFile);
    //writeFile.close();
    std::ifstream readFile("tasks.dat", std::ios::in | std::ios::binary);
    Exam exam;
    readExam(readFile,exam);
    readFile.close();
    //да се симулира провеждане на контролно в конзолата: да се принтира условието на всяка задача, 
    //да се въвежда в конзолата отговорът, който ученикът смята за правилен, и в края 
    //на контролното да принтира колко точки от максималния брой е изкарал ученикът.
    unsigned maxPoints = 0;
    for (size_t i = 0; i < EXAMSIZE; i++)
    {
        Task current=exam.getCurrentTask(i);
        std::cout << current.getTaskQuestion() << std::endl;
        std::cout << "Please give us your Answer."<<std::endl<<"It is either a, b, c or d." << std::endl;
        std::cout << "Points you can get: " << current.getPoints()<<std::endl;
        char answer;
        std::cin >> answer;
        if (answer == current.getSymbol()) {
            maxPoints += current.getPoints();
        }
    }
    std::cout << "You got: " << maxPoints<<" points";
}