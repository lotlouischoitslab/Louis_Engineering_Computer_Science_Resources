import numpy as np 
import pandas as pd 
from src.utils import Graph

'''
Seoul Metro Machine Problem
Author: Louis Sungwoo Cho
Created: 1/9/2023
Dataset: https://develop-dream.tistory.com/89 (서울지하철 경로찾기 Seoul Metro Shortest Paths)
'''

def load_data():
    file = pd.read_excel('train_stations.xlsx')
    df = pd.DataFrame(file)
    return df


def main():
    print('Seoul Metro Machine Problem by Louis Sungwoo Cho')
    df = load_data()
    station_nodes = [
        'Jongno_3_Ga', #종로3가
        'Jongno_5_Ga', #종로5가
        'Dongdaemun', #동대문
        'Jonggak', #종각
        'City_Hall', #시청
        'Euljiro_1_Ga', #을지로입구
        'Euljiro_3_Ga', #을지로3가
        'Euljiro_4_Ga', #을지로4가
        'Dongdaemun_Design_Plaza', #동대문역사문화공원
        'Seoul_Station', #서울역
        'Hoehyeon', #회현
        'Myeongdong', #명동
        'Chungmuro' #충무로
    ] 

    louis_network = Graph(station_nodes) #This should be a Graph object receiving a 1-D array

    #Testing Purpose
    
    nodes1 = [0,1,2,3,4]
    graphs1 = Graph(nodes1)
    graphs1.addedge(0,1,2)
    graphs1.addedge(1,2,2)
    graphs1.addedge(2,3,4)
    graphs1.addedge(3,0,5)
    graphs1.addedge(3,4,3)
    graphs1.addedge(4,0,1)

    #Print Graph
    print('Graph')
    graphs1.print_graph()

    source = 2
    #BFS Testing
    print('BFS')
    print(graphs1.bfs(source))

    #DFS Testing
    print('DFS')
    print(graphs1.dfs(source))

if __name__ == '__main__':
    main()