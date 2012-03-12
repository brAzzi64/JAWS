#include "bashcommander.h"
#include <iostream>
#include <cstdio>
#include <QDebug>

BashCommander::BashCommander()
{
}

QString BashCommander::executeCommand(const QString& command)
{
    char* sentence = command.toLocal8Bit().data();
    FILE* pipe = popen(sentence, "r");
    if (!pipe) return "ERROR";

    char buffer[128];
    QString result = "";

    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}
