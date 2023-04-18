m_list = [['1', '1', '1', '1', '1', '1'], ['e', '0', '0', '0', '0', '1'], ['1', '0', '1', '1', '0', '1'], ['1', '0', '1', '0', '0', 'x'], ['1', '0', '0', '0', '1', '1'], ['1', '1', '1', '1', '1', '1']]
m_graph = {}
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
start = []
end = []
for x in range(6):
    for y in range(6):
        if m_list[y][x] == 'x':
            end.extend([y, x])
            m_list[y][x] = '0'
for x in range(6):
    for y in range(6):
        if m_list[y][x] == 'e':
            start.extend([y, x])
            m_list[y][x] = '0'
        if (m_list[y][x] == '0'):
            m_graph[(y, x)] = []
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                if nx < 0 or nx >= 6  or ny < 0 or ny >= 6:
                    continue
                if m_list[ny][nx] != '0':
                    continue
                m_graph[(y, x)].append((ny, nx))
print("=" * 10, "graph", "=" * 10)
for k, v in m_graph.items():
    print(k, v)
def bfs(v):
    visit = list()
    stack = list()
    stack.append(v)
    while stack:
        node = stack.pop()
        if node[0] == end[0] and node[1] == end[1]:
            return visit
        if node not in visit:
            visit.append(node)
            stack.extend(m_graph[node])
    return visit
print("=" * 10, "최단 경로", "=" * 10)
shortcut = bfs(tuple(start))
for p in shortcut:
    print(p, end=" ")
print(tuple(end))
print("=" * 10, "최단 경로 길이", "=" * 10)
print(len(shortcut))

