#include "TurnTable.h"

TurnTable::TurnTable()
{
	resize(800, 800);
	m_color_list = {
	qRgb(76,180,231),
	qRgb(255,192,159),
	qRgb(255,238,147),
	qRgb(226,219,190),
	qRgb(153,163,128),
	qRgb(76,180,231),
	qRgb(255,192,159),
	qRgb(255,238,147),
	qRgb(226,219,190),
	qRgb(153,163,128),
	};
	m_word_list = {
		QString("一等奖1"),
		QString("二等奖2"),
		QString("三等奖3"),
		QString("四等奖4"),
		QString("五等奖5"),
		QString("一等奖6"),
		QString("二等奖7"),
		QString("三等奖8"),
		QString("四等奖9"),
		QString("五等奖10"),
	};
	pointer_color = QColor(0, 127, 127, 191);
	m_backingStore = new QBackingStore(this);
	m_pTimer = new QTimer(this);
	m_pTimer->setInterval(INTERVAL);
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(changeRorate()));
	m_nowRorate = -75;
}


TurnTable::~TurnTable()
{
}

bool TurnTable::event(QEvent * event)
{
	if (event->type() == QEvent::Resize
		|| event->type() == QEvent::UpdateRequest)
	{
		QRect rect(QPoint(), geometry().size());
		m_backingStore->resize(rect.size());
		m_backingStore->beginPaint(rect);
		QPainter p(m_backingStore->paintDevice());
		render(&p);
		m_backingStore->endPaint();
		m_backingStore->flush(rect);
		return true;
	}

	return QWindow::event(event);
}

void TurnTable::render(QPainter * painter)
{

	//qDebug("start render");
	// 指针

	/***********画圆盘************/
	// 设置抗锯齿
	painter->setRenderHint(QPainter::Antialiasing);

	int d = qMin(width(), height());
	int x = (width() + height() - d * 2) / 2;
	int y = 0;
	if (d == width())
	{
		x = x + y;
		y = x - y;
		x = x - y;
	}
	painter->save();
	// qDebug("x = %d,y = %d",x,y);
	// 绘制颜色圆盘
	for (size_t i = 0; i < m_color_list.size(); i++)
	{
		painter->setBrush(QBrush(QColor::fromRgb(m_color_list[i])));
		painter->drawPie(x, y, d, d, i * 36 * 16, 36 * 16);
	}
	painter->restore();

	painter->save();
	// 绘制文字
	painter->translate(width() / 2, height() / 2);
	for (size_t i = 0; i < m_word_list.size(); i++)
	{
		//int i = m_word_list.size();
		painter->rotate(-360.0 / m_word_list.size() / 2);
		painter->drawText(d / 4, 0, m_word_list[i]);
		painter->rotate(-360.0 / m_word_list.size() / 2);

	}
	painter->restore();

	painter->save();
	painter->translate(width() / 2, height() / 2);
	painter->scale(d / 200.0, d / 200.0);
	painter->setPen(Qt::NoPen);
	painter->setBrush(pointer_color);
	painter->rotate(-m_nowRorate);
	painter->drawConvexPolygon(hourHand, 3);
	painter->restore();
}

void TurnTable::set_resultLabel(QLabel * Label)
{
	textLabel = Label;
}


/*******************slots*************************/
void TurnTable::changeRorate()
{
	//qDebug() << m_nowRorate << " " << m_targetRorate;
	m_nowRorate += m_everyRorate;
	requestUpdate();
	if (m_nowRorate >= m_targetRorate)
	{
		m_pTimer->stop();
		int number = (m_nowRorate + 90) % 360 / (360 / m_word_list.size());
		//qDebug() << number;
		textLabel->setText(m_word_list[number]);
		//m_nowRorate = 0;
	}
}

void TurnTable::set_RandTimer()
{
	// 产生随机角度
	m_nowRorate = -90;
	do
	{
		QTime t;
		t = QTime::currentTime();
		qsrand(t.msec() + t.second() * 1000);
		m_targetRorate = qrand() % 360;
	} while (360 / m_color_list.size() % m_targetRorate == 0);
	m_targetRorate += 360;
	m_pTimer->start();
	//textLabel = Label;
}