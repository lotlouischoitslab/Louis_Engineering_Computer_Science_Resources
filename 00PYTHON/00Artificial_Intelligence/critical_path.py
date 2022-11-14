from criticalpath import Node

def link_project(a,b,p):
    return p.link(a,b)

if __name__ == '__main__':
    print('Welcome to Construction Management! Use this to schedule your project!')
    p = Node('project')
    a = p.add(Node('A',duration=2,lag=0))
    b = p.add(Node('B',duration=4,lag=0))
    c = p.add(Node('C',duration=5,lag=0))
    d = p.add(Node('D',duration=6,lag=0))
    e = p.add(Node('E',duration=2,lag=0))
    f = p.add(Node('F',duration=8,lag=0))

    schedule = link_project(a,b,p)
    schedule = link_project(a,c,schedule)
    schedule = link_project(b,d,schedule)
    schedule = link_project(b,e,schedule)
    schedule = link_project(d,f,schedule)
    schedule = link_project(e,f,schedule)

    schedule.update_all()
    critcal_path = p.get_critical_path()
    print('Critical Path:',critcal_path)
    duration = schedule.duration
    print('Duration of the critical path:',duration)