/********************************************************************************
** Form generated from reading UI file 'main_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_widget
{
public:
    QGraphicsView *graphic_view;
    QPushButton *load_map_bt;
    QPushButton *load_cbs_result_bt;

    void setupUi(QWidget *main_widget)
    {
        if (main_widget->objectName().isEmpty())
            main_widget->setObjectName(QStringLiteral("main_widget"));
        main_widget->resize(1200, 800);
        graphic_view = new QGraphicsView(main_widget);
        graphic_view->setObjectName(QStringLiteral("graphic_view"));
        graphic_view->setGeometry(QRect(400, 0, 800, 800));
        load_map_bt = new QPushButton(main_widget);
        load_map_bt->setObjectName(QStringLiteral("load_map_bt"));
        load_map_bt->setEnabled(true);
        load_map_bt->setGeometry(QRect(50, 40, 271, 71));
        load_cbs_result_bt = new QPushButton(main_widget);
        load_cbs_result_bt->setObjectName(QStringLiteral("load_cbs_result_bt"));
        load_cbs_result_bt->setEnabled(true);
        load_cbs_result_bt->setGeometry(QRect(50, 150, 271, 81));

        retranslateUi(main_widget);

        QMetaObject::connectSlotsByName(main_widget);
    } // setupUi

    void retranslateUi(QWidget *main_widget)
    {
        main_widget->setWindowTitle(QApplication::translate("main_widget", "Form", Q_NULLPTR));
        load_map_bt->setText(QApplication::translate("main_widget", "Load Map file", Q_NULLPTR));
        load_cbs_result_bt->setText(QApplication::translate("main_widget", "Load CBS result", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_widget: public Ui_main_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WIDGET_H
