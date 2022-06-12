#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QWidget *widget;
   QVBoxLayout *verticalLayout;
   QHBoxLayout *horizontalLayout;
   QLabel *label;
   QLineEdit *ed_user;
   QHBoxLayout *horizontalLayout_2;
   QLabel *label_2;
   QLineEdit *ed_pwd;
   QHBoxLayout *horizontalLayout_3;
   QPushButton *btn_login;
   QPushButton *btn_cancel;

    void addControls();
    void retranslateUi(QWidget *Widget);
    void btn_login_clicked();
    void btn_cancel_clicked();
};


#endif // WIDGET_H
