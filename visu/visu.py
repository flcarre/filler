#!/usr/bin/python

import sys
from tkinter import *

file = open("vlogs.txt", "w")
debug = True
box_w = 30
box_h = 30

def log(s):
	if debug:
		file.write(s)
		file.flush()

def read_line():
	line = sys.stdin.readline()
	log("read: " + line + '\n')
	return line

def read_until(s):
	line = read_line()
	if s not in line:
		return read_until(s)
	else:
		return line

def close(event):
	sys.exit()

class Player:
	def __init__(self, number):
		line = read_until('p' + str(number))
		self.name = line.split(' ')[4].split('/')[-1].split('.filler')[0]
		self.score = 0

	def generate_label_text(self):
		return self.name + ': ' + str(self.score)

class Plateau:
	def __init__(self):
		line = read_line().replace(':', '').split(' ')
		self.set_size(int(line[-1]), int(line[-2]))
		read_line()
		self.state = -1
		self.boards = []
		self.read()

	def read(self):
		self.state += 1
		self.set_current(self.state)
		board = [[0 for x in range(self.size_x)] for y in range(self.size_y)]
		for i in range(0, self.size_y):
			line = read_line().strip().split(' ')[1]
			for (j, c) in enumerate(line):
				board[i][j] = {
					'.': 0,
					'O': 1,
					'o': 2,
					'X': 3,
					'x': 4
				}[c]
		self.boards.append(board)

	def set_size(self, x, y):
		self.size_x = x
		self.size_y = y
		self.board = [[0 for x in range(self.size_x)] for y in range(self.size_y)]

	def get_board(self):
		return self.boards[self.__current]
	
	def get_current(self):
		return self.__current
	def set_current(self, value):
		if value <= self.state and value >= 0:
			self.__current = value

class Game:
	def __init__(self):
		self.player1 = Player(1)
		self.player2 = Player(2)
		self.plateau = Plateau()
		self.finished = False
		self.init_root()
		self.matrix = [[0 for x in range(self.plateau.size_x)] for y in range(self.plateau.size_y)]
		self.label1 = Label(self.root, text=self.player1.generate_label_text(), foreground='purple')
		self.label2 = Label(self.root, text=self.player2.generate_label_text(), foreground='blue')
		self.canvas = Canvas(self.root, width=self.plateau.size_x * box_w + 3, height=self.plateau.size_y * box_h + 3)
		self.label1.pack()
		self.label2.pack()
		self.canvas.pack()
		self.init_window()
		self.bind_events()

	def bind_events(self):
		self.root.bind('<space>', self.toggle)
		self.root.bind('<Left>', self.back)
		self.root.bind('<Right>', self.forward)

	def init_root(self):
		self.root = Tk()
		self.root.bind('<Escape>', close)

	def init_window(self):
		for (i, row) in enumerate(self.matrix):
			for (j, el) in enumerate(row):
				x0 = j * box_w + 3
				y0 = i * box_h + 3
				x1 = x0 + box_w
				y1 = y0 + box_h
				fill = 'black'
				self.matrix[i][j] = self.canvas.create_rectangle(x0, y0, x1, y1, fill='black', outline='black', width=1)

	def set_window_colors(self):
		board = self.plateau.get_board()

		for (i, row) in enumerate(board):
			for (j, el) in enumerate(row):
				fill = 'black'
				fill = {
					0: 'black',
					1: 'purple',
					2: 'orange',
					3: 'blue',
					4: 'yellow'
				}[el]
				self.canvas.itemconfig(self.matrix[i][j], fill=fill)

	def routine(self):
		line = ''
		if self.finished:
			return
		while 'Plateau' not in line:
			line = read_line()
			if 'An error' in line or 'fin' in line:
				self.finished = True
				return self.stop()
			elif '<got (O):' in line:
				self.player1.score += 1
			elif '<got (X):' in line:
				self.player2.score += 1
		read_line()
		self.label1.config(text=self.player1.generate_label_text())
		self.label2.config(text=self.player2.generate_label_text())
		self.plateau.read()
		self.draw()
		if self.running:
			self.root.after(0, self.routine)

	def toggle(self, event):
		if self.running:
			self.stop()
		else:
			self.start()

	def start(self):
		self.running = True
		self.draw()
		self.root.configure(background='black')
		self.root.after(100, self.routine)
		self.root.mainloop()
	
	def stop(self):
		self.running = False

	def draw(self):
		self.set_window_colors()
		self.canvas.update()

	def forward(self, event):
		self.plateau.set_current(self.plateau.get_current() + 1)
		self.draw()
	def back(self, event):
		self.plateau.set_current(self.plateau.get_current() - 1)
		self.draw()

Game().start()