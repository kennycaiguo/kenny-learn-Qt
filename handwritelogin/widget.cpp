#include "widget.h"
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QMessageBox>
#include<QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   addControls();
   ed_pwd->setEchoMode(QLineEdit::Password);
    connect(btn_login,&QPushButton::clicked,this,&Widget::btn_login_clicked);
    connect(btn_cancel,&QPushButton::clicked,this,&Widget::btn_cancel_clicked);//注意connect函数的新语法，用旧语法没有效果
}

Widget::~Widget()
{
}

//添加控件功能
void Widget::addControls()
{
    if (this->objectName().isEmpty())
               this->setObjectName(QString::fromUtf8("Widget"));
   this->resize(471, 303);
   widget = new QWidget(this);
   widget->setObjectName(QString::fromUtf8("widget"));
   widget->setGeometry(QRect(90, 60, 311, 181));
   verticalLayout = new QVBoxLayout(widget);
   verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
   verticalLayout->setContentsMargins(0, 0, 0, 0);
   horizontalLayout = new QHBoxLayout();
   horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
   label = new QLabel(widget);
   label->setObjectName(QString::fromUtf8("label"));

   horizontalLayout->addWidget(label);

   ed_user = new QLineEdit(widget);
   ed_user->setObjectName(QString::fromUtf8("ed_user"));

   horizontalLayout->addWidget(ed_user);


   verticalLayout->addLayout(horizontalLayout);

   horizontalLayout_2 = new QHBoxLayout();
   horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
   label_2 = new QLabel(widget);
   label_2->setObjectName(QString::fromUtf8("label_2"));

   horizontalLayout_2->addWidget(label_2);

   ed_pwd = new QLineEdit(widget);
   ed_pwd->setObjectName(QString::fromUtf8("ed_pwd"));
   ed_pwd->setEchoMode(QLineEdit::Normal);

   horizontalLayout_2->addWidget(ed_pwd);


   verticalLayout->addLayout(horizontalLayout_2);

   horizontalLayout_3 = new QHBoxLayout();
   horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
   btn_login = new QPushButton(widget);
   btn_login->setObjectName(QString::fromUtf8("btn_login"));

   horizontalLayout_3->addWidget(btn_login);

   btn_cancel = new QPushButton(widget);
   btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

   horizontalLayout_3->addWidget(btn_cancel);


   verticalLayout->addLayout(horizontalLayout_3);

   QWidget::setTabOrder(ed_user, ed_pwd);
   QWidget::setTabOrder(ed_pwd, btn_login);
   QWidget::setTabOrder(btn_login, btn_cancel);

   retranslateUi(this);

   QMetaObject::connectSlotsByName(this);
}

 void Widget::retranslateUi(QWidget *Widget)
   {
       Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
       label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
       label_2->setText(QApplication::translate("Widget", "\345\257\206 \347\240\201", nullptr));
       btn_login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
       btn_cancel->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
   }

 void Widget::btn_login_clicked(void)
 {
    //QMessageBox::information(nullptr,"greeting","hello,how are u?");
     QString strusr = this->ed_user->text().trimmed();
     QString strpwd = ed_pwd->text().trimmed();
     if(strusr=="" && strpwd=="")
     {
         QMessageBox::critical(nullptr,"error!!!","用户名和密码不能为空");
         if(strusr=="")
         {
             ed_user->setFocus();
         }
         else if(strpwd=="")
         {
             ed_pwd->setFocus();
         }
     }else{
         if(strusr=="kenny" && strpwd=="12345")
         {
             QMessageBox::information(nullptr,"欢迎!!!","登录成功");
         }else if(strusr!="kenny")
         {
             QMessageBox::critical(nullptr,"error!!!","用户名错误，请改进");
             ed_user->setFocus();
         }else if (strpwd!="12345") {
           QMessageBox::critical(nullptr,"error!!!","密码错误，请改进");
           ed_pwd->setFocus();
        }
     }

 }

 void Widget::btn_cancel_clicked()
 {
    QMessageBox::information(nullptr,"再见!!!","欢迎你下次再使用本软件，谢谢");
    this->close();
 }
