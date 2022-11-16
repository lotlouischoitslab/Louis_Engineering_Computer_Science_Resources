from criticalpath import Node

def link_project(a,b,project):
    return project.link(a,b)

if __name__ == '__main__':
    print('Welcome to Construction Management! Use this to schedule your project!')
    p = Node('project')
    a = p.add(Node('A',duration=2,lag=0))
    b = p.add(Node('B',duration=6,lag=0))
    c = p.add(Node('C',duration=4,lag=0))
    d = p.add(Node('D',duration=3,lag=0))
    e = p.add(Node('E',duration=5,lag=0))
    f = p.add(Node('F',duration=4,lag=0))
    g = p.add(Node('G',duration=2,lag=0))

    schedule = link_project(a,d,p)
    schedule = link_project(a,f,schedule)
    schedule = link_project(b,g,schedule)
    schedule = link_project(c,e,schedule)
    schedule = link_project(d,g,schedule)
    schedule = link_project(e,g,schedule)

    schedule.update_all()
    critcal_path = p.get_critical_path()
    print('Critical Path:',critcal_path)
    duration = schedule.duration
    print('Duration of the critical path:',duration)