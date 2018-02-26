#ifndef READFILE_H
#define READFILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class readFile : public QObject
{
    Q_OBJECT
public:
    explicit readFile(QObject *parent = nullptr);
     QString text;


signals:

public slots:

private:
    QFile file;

};

#endif // READFILE_H
