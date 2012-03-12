#ifndef BASHCOMMANDER_H
#define BASHCOMMANDER_H

#include <QString>

class BashCommander
{
public:
    BashCommander();

    QString executeCommand(const QString& command);
};

#endif // BASHCOMMANDER_H
