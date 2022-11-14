from criticalpath import Node

def link_project(a,b,c,d,e,f,p):
    return p.link(a,b).link(a,c).link(b,d).link(b,e).link(d,f).link(e,f)


if __name__ == '__main__':
    print('Welcome to Construction Management! Use this to schedule your project!')
    p = Node('project')
    a = p.add(Node('A',duration=2,lag=0))
    b = p.add(Node('B',duration=4,lag=0))
    c = p.add(Node('C',duration=5,lag=0))
    d = p.add(Node('D',duration=6,lag=0))
    e = p.add(Node('E',duration=2,lag=0))
    f = p.add(Node('F',duration=8,lag=0))

    schedule = link_project(a,b,c,d,e,f,p)
    schedule.update_all()
    critcal_path = p.get_critical_path()
    print('Critical Path:',critcal_path)
    duration = schedule.duration
    print('Duration of the critical path:',duration)