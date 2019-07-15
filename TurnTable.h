#pragma once
#pragma execution_character_set("utf-8") 
#include <QtWidgets/QWidget>
#include <QtGui>
#include <qwindow.h>
#include <synchapi.h>
#include <qlist.h>
#include <qpainter.h>
#include <QHBoxLayout>
#include <qpushbutton.h>
#include <QTimer>
#include <ctime>
#include <qdebug.h>
#include <qbackingstore.h>
#include <qlabel.h>
#include <QTime>

class TurnTable :
	public QWindow
{
	Q_OBJECT
public:
	TurnTable();
	~TurnTable();
	void set_resultLabel(QLabel *textLabel);
public slots:
	void set_RandTimer();
	void changeRorate();
protected:
	bool event(QEvent* event) override;
	void render(QPainter *painter);
	
	//void paintEvent(QPaintEvent*);
private:
	const int INTERVAL = 5;
	const int m_everyRorate = 1;
	int m_nowRorate = 30;
	int m_targetRorate = 0;
	QList<QRgb> m_color_list;
	QList<QString> m_word_list;
	QPainter* pointer;

	const QPoint hourHand[3] = {
		QPoint(7,8),
		QPoint(-7,8),
		QPoint(0,-40)
	};
	// 指针颜色
	QColor pointer_color;
	QTimer *m_pTimer;
	QBackingStore *m_backingStore;
	QLabel * textLabel;
};

