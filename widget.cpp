#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , isPlayerX(true)
{
    ui->setupUi(this);
    
    // Connect all buttons to the click handler
    connect(ui->button0, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button1, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button2, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button3, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button4, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button5, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button6, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button7, &QPushButton::clicked, this, &Widget::onButtonClicked);
    connect(ui->button8, &QPushButton::clicked, this, &Widget::onButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && button->text().isEmpty()) {
        if (isPlayerX) {
            button->setText("X");
        } else {
            button->setText("O");
        }
        isPlayerX = !isPlayerX;
    }
}
