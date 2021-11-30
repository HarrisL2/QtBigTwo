/********************************************************************************
** Form generated from reading UI file 'startingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTINGWINDOW_H
#define UI_STARTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartingWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *Main;
    QVBoxLayout *verticalLayout_16;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Title;
    QLabel *label;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *CreateRoom;
    QWidget *horizontalWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *PlayerNameBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *verticalWidget_5;
    QVBoxLayout *verticalLayout_9;
    QPushButton *JoinRoom;
    QWidget *horizontalWidget_9;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *IPBox;
    QPlainTextEdit *PortBox;
    QWidget *horizontalWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QPushButton *RulesButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *CreditsButton;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_17;
    QGraphicsView *graphicsView;
    QWidget *page;

    void setupUi(QWidget *StartingWindow)
    {
        if (StartingWindow->objectName().isEmpty())
            StartingWindow->setObjectName(QString::fromUtf8("StartingWindow"));
        StartingWindow->resize(800, 658);
        StartingWindow->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(StartingWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(StartingWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        Main = new QWidget();
        Main->setObjectName(QString::fromUtf8("Main"));
        verticalLayout_16 = new QVBoxLayout(Main);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalWidget = new QWidget(Main);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 1, -1, -1);
        Title = new QLabel(horizontalWidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Title->sizePolicy().hasHeightForWidth());
        Title->setSizePolicy(sizePolicy1);
        Title->setMaximumSize(QSize(350, 350));
        Title->setTextFormat(Qt::PlainText);
        Title->setPixmap(QPixmap(QString::fromUtf8(":/cards/png/logo.png")));
        Title->setScaledContents(false);
        Title->setAlignment(Qt::AlignCenter);
        Title->setWordWrap(false);

        horizontalLayout_5->addWidget(Title);

        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(20);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);


        verticalLayout->addWidget(horizontalWidget);

        horizontalWidget_2 = new QWidget(verticalWidget);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(45);
        sizePolicy3.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalWidget_2 = new QWidget(horizontalWidget_2);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy4);
        verticalLayout_7 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        verticalLayout_3->addWidget(verticalWidget_2);

        CreateRoom = new QPushButton(horizontalWidget_2);
        CreateRoom->setObjectName(QString::fromUtf8("CreateRoom"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(8);
        sizePolicy5.setHeightForWidth(CreateRoom->sizePolicy().hasHeightForWidth());
        CreateRoom->setSizePolicy(sizePolicy5);
        QFont font1;
        font1.setPointSize(10);
        CreateRoom->setFont(font1);

        verticalLayout_3->addWidget(CreateRoom);

        horizontalWidget_3 = new QWidget(horizontalWidget_2);
        horizontalWidget_3->setObjectName(QString::fromUtf8("horizontalWidget_3"));
        sizePolicy4.setHeightForWidth(horizontalWidget_3->sizePolicy().hasHeightForWidth());
        horizontalWidget_3->setSizePolicy(sizePolicy4);
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        PlayerNameBox = new QPlainTextEdit(horizontalWidget_3);
        PlayerNameBox->setObjectName(QString::fromUtf8("PlayerNameBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(PlayerNameBox->sizePolicy().hasHeightForWidth());
        PlayerNameBox->setSizePolicy(sizePolicy6);
        PlayerNameBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PlayerNameBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PlayerNameBox->setTabChangesFocus(true);

        horizontalLayout_4->addWidget(PlayerNameBox);


        verticalLayout_3->addWidget(horizontalWidget_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalWidget_5 = new QWidget(horizontalWidget_2);
        verticalWidget_5->setObjectName(QString::fromUtf8("verticalWidget_5"));
        sizePolicy4.setHeightForWidth(verticalWidget_5->sizePolicy().hasHeightForWidth());
        verticalWidget_5->setSizePolicy(sizePolicy4);
        verticalLayout_9 = new QVBoxLayout(verticalWidget_5);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        verticalLayout_4->addWidget(verticalWidget_5);

        JoinRoom = new QPushButton(horizontalWidget_2);
        JoinRoom->setObjectName(QString::fromUtf8("JoinRoom"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(8);
        sizePolicy7.setHeightForWidth(JoinRoom->sizePolicy().hasHeightForWidth());
        JoinRoom->setSizePolicy(sizePolicy7);
        JoinRoom->setFont(font1);

        verticalLayout_4->addWidget(JoinRoom);

        horizontalWidget_9 = new QWidget(horizontalWidget_2);
        horizontalWidget_9->setObjectName(QString::fromUtf8("horizontalWidget_9"));
        sizePolicy4.setHeightForWidth(horizontalWidget_9->sizePolicy().hasHeightForWidth());
        horizontalWidget_9->setSizePolicy(sizePolicy4);
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_9);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        IPBox = new QPlainTextEdit(horizontalWidget_9);
        IPBox->setObjectName(QString::fromUtf8("IPBox"));
        QSizePolicy sizePolicy8(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy8.setHorizontalStretch(12);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(IPBox->sizePolicy().hasHeightForWidth());
        IPBox->setSizePolicy(sizePolicy8);
        IPBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IPBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(IPBox);

        PortBox = new QPlainTextEdit(horizontalWidget_9);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        QSizePolicy sizePolicy9(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy9.setHorizontalStretch(4);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(PortBox->sizePolicy().hasHeightForWidth());
        PortBox->setSizePolicy(sizePolicy9);
        PortBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PortBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(PortBox);


        verticalLayout_4->addWidget(horizontalWidget_9);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addWidget(horizontalWidget_2);

        horizontalWidget_10 = new QWidget(verticalWidget);
        horizontalWidget_10->setObjectName(QString::fromUtf8("horizontalWidget_10"));
        sizePolicy3.setHeightForWidth(horizontalWidget_10->sizePolicy().hasHeightForWidth());
        horizontalWidget_10->setSizePolicy(sizePolicy3);
        horizontalLayout_11 = new QHBoxLayout(horizontalWidget_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);

        RulesButton = new QPushButton(horizontalWidget_10);
        RulesButton->setObjectName(QString::fromUtf8("RulesButton"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(RulesButton->sizePolicy().hasHeightForWidth());
        RulesButton->setSizePolicy(sizePolicy10);
        RulesButton->setFont(font1);

        verticalLayout_6->addWidget(RulesButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_4);


        horizontalLayout_11->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_5);

        CreditsButton = new QPushButton(horizontalWidget_10);
        CreditsButton->setObjectName(QString::fromUtf8("CreditsButton"));
        sizePolicy10.setHeightForWidth(CreditsButton->sizePolicy().hasHeightForWidth());
        CreditsButton->setSizePolicy(sizePolicy10);
        CreditsButton->setFont(font1);

        verticalLayout_5->addWidget(CreditsButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_6);


        horizontalLayout_11->addLayout(verticalLayout_5);


        verticalLayout->addWidget(horizontalWidget_10);


        verticalLayout_16->addWidget(verticalWidget);

        stackedWidget->addWidget(Main);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        verticalLayout_17 = new QVBoxLayout(page_6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        graphicsView = new QGraphicsView(page_6);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_17->addWidget(graphicsView);

        stackedWidget->addWidget(page_6);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(StartingWindow);

        QMetaObject::connectSlotsByName(StartingWindow);
    } // setupUi

    void retranslateUi(QWidget *StartingWindow)
    {
        StartingWindow->setWindowTitle(QCoreApplication::translate("StartingWindow", "Form", nullptr));
        Title->setText(QString());
        label->setText(QCoreApplication::translate("StartingWindow", "Big TwUNO", nullptr));
        CreateRoom->setText(QCoreApplication::translate("StartingWindow", "Create Room", nullptr));
        PlayerNameBox->setPlaceholderText(QCoreApplication::translate("StartingWindow", "Player Name", nullptr));
        JoinRoom->setText(QCoreApplication::translate("StartingWindow", "Join Room", nullptr));
        IPBox->setPlaceholderText(QCoreApplication::translate("StartingWindow", "IP", nullptr));
        PortBox->setPlaceholderText(QCoreApplication::translate("StartingWindow", "Port", nullptr));
        RulesButton->setText(QCoreApplication::translate("StartingWindow", "Rules", nullptr));
        CreditsButton->setText(QCoreApplication::translate("StartingWindow", "Credits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartingWindow: public Ui_StartingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTINGWINDOW_H
