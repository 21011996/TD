#pragma once

namespace td
{

struct IDrawable
{
	virtual ~IDrawable() {}
	virtual void draw(int x, int y) = 0;
};

struct MyLine : IDrawable
{
	MyLine(int x1, int y1, int x2, int y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}
	void draw(int x, int y) override;

private :
	int m_x1, m_y1, m_x2, m_y2;
};

struct MyEllipse : IDrawable
{
	MyEllipse(int x, int y, int a, int b): m_x(x), m_y(y), m_a(a), m_b(b) {}
	void draw(int x, int y) override;

private :
	int m_x, m_y, m_a, m_b;
};

struct MyRect : IDrawable
{
	MyRect(int lx, int ty, int rx, int by) : m_lx(lx), m_ty(ty), m_rx(rx), m_by(by) {}
	void draw(int x, int y) override;

private :
	int m_lx, m_ty, m_rx, m_by;
};

struct MyPoint : IDrawable
{
	MyPoint(int x, int y) : m_x(x), m_y(y) {}
	void draw(int x, int y) override;

private :
	int m_x, m_y;
};

} // namespace td
