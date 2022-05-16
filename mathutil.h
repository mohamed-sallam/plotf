#ifndef MATHUTIL_H
#define MATHUTIL_H
#define OP_NOT_FOUND -1
#define FIRST_ELEMENT 0
#include <QString>
#include <QVector>
#include <QtMath>

class MathUtil
{
public:
    MathUtil();
    static long double substituteIntoFunc(const QString &function, const QString &variableName, const long double &variableValue);
    static QStringList splitMathematicalExpression(QString mathematicalExpression);
private:
    static int getIndex(const QStringList &haystack, const QVector<QString> &needles);
    static bool isdouble(const QString &str);
    static long double stringNumberOrVariableToLongDouble(const QString &numberOrVariable, const QString &variableName, const long double &variableValue, bool &error);
};

#endif // MATHUTIL_H
