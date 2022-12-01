#include <QTextStream>

int main(int argc, char *argv[])
{
    QTextStream stream(stdout);
    stream << "Hello world!" << endl;
}
