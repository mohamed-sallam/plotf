#include "mathutil.h"

MathUtil::MathUtil()
{

}

QStringList MathUtil::splitMathematicalExpression(QString mathematicalExpression)
{
    const QVector<QString> operators {"^", "*", "/", "+", "-"};
    for(const auto &op: operators)
        mathematicalExpression.replace(op, " " + op + " ");
    return mathematicalExpression.split(" ");
}

long double MathUtil::substituteIntoFunc(const QString &function, const QString &variableName, const long double &variableValue)
{
    bool error {false};
    QStringList func = splitMathematicalExpression(function);
    if (func.length() == 1)
        return stringNumberOrVariableToLongDouble(func.at(FIRST_ELEMENT), variableName, variableValue, error);
    const QVector<QVector<QString>> levels {   {"^"},
                                               {"*", "/"},
                                               {"+", "-"}   };
    for(const auto &level: levels){
        for( ; error == false; ){
            int r {getIndex(func, level)};
            if (r == OP_NOT_FOUND) break;
            long double n1 {stringNumberOrVariableToLongDouble(func.at(r-1), variableName, variableValue, error)},
                        n2 {stringNumberOrVariableToLongDouble(func.at(r+1), variableName, variableValue, error)};
            if ( func[r] == "^" && !(std::isnan(qPow(n1, n2))) )
                func[r+1] = QString::fromStdString(std::to_string(qPow(n1, n2)));
            else if ( func.at(r) == "*" )
                func[r+1] = QString::fromStdString(std::to_string(n1 * n2));
            else if ( (func.at(r) == "/") && n2 != 0 )
                func[r+1] = QString::fromStdString(std::to_string(n1 / n2));
            else if ( func.at(r) == "+" )
                func[r+1] = QString::fromStdString(std::to_string(n1 + n2));
            else if ( func.at(r) == "-" )
                func[r+1] = QString::fromStdString(std::to_string(n1 - n2));
            else{
                error = true;
                break;
            }
            func.erase(func.begin() +  r - 1, func.begin() + r + 1);
        }
    }
    return (error)?qQNaN():std::stold(func[FIRST_ELEMENT].toStdString());
}

int MathUtil::getIndex(const QStringList &haystack, const QVector<QString> &needles)
{
    int index {OP_NOT_FOUND};

    for (const auto &needle: needles){
        auto it {std::find(haystack.begin(), haystack.end(), needle)};

        // If element was found
        if ( it != haystack.end() && (index == OP_NOT_FOUND || std::distance(haystack.begin(), it) < index) )
                index = std::distance(haystack.begin(), it);
    }
    return index;
}

bool MathUtil::isdouble(const QString &str)
{
    for(const auto &chr: str)
        if(!(chr.isDigit() || chr == '.' || chr == '-'))
            return false;
    return true;
}

long double MathUtil::stringNumberOrVariableToLongDouble(const QString &numberOrVariable, const QString &variableName, const long double &variableValue, bool &error)
{
    if (numberOrVariable == variableName)
        return variableValue;
    else if (isdouble(numberOrVariable))
        return std::stold(numberOrVariable.toStdString());
    else {
        error = true;
        return qQNaN();
    }
}
