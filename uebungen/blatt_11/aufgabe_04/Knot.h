#ifndef KNOT_H_
#define KNOT_H_

class Knot
{
  private:
	bool visited;
	int name;

  public:
	Knot(int name);
	virtual ~Knot();
	int get_name();
	bool get_visited();
	void set_visited(bool newState);
};

#endif /* KNOT_H_ */
