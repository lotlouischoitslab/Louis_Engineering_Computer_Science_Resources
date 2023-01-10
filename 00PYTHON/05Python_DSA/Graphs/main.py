import numpy as np 
import pandas as pd 
from src.utils import Graph

'''Graphs Machine Problem
Author: Louis Sungwoo Cho
Created: 1/9/2023
Dataset: https://develop-dream.tistory.com/89 (서울지하철 경로찾기 Seoul Metro Shortest Paths)
'''

def load_data():
    file = pd.read_excel('train_stations.xlsx')
    df = pd.DataFrame(file)
    return df


def main():
    print('Graphs Machine Problem by Louis Sungwoo Cho')
    df = load_data()
    station_nodes = [
        'Jongno_3_Ga', #종로3가
        'Jongno_5_Ga', #종로5가
        'Dongdaemun', #동대문
        'Jongak', #종각
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

    #Testing Purpose
    
    #This should be a list of nodes
    louis_network = Graph(station_nodes) #This should be a Graph object receiving a 1-D array

if __name__ == '__main__':
    main()