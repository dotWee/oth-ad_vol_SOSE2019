#ifndef KNOT_H_
#define KNOT_H_

class Knot
{
  private:
	Knot *left;
	Knot *right;
	int value;
	bool used;

  public:
	Knot();
	virtual ~Knot();
	Knot *get_left();
	Knot *get_right();
	int get_value();
	void set_left(Knot *knot);
	void set_right(Knot *knot);
	void set_value(int val);
	bool isUsed();
};

#endif /* KNOT_H_ */
