"""
Hierarchical Runtime Plotter
"""
import csv
import matplotlib.pyplot as plt
from optparse import OptionParser as OP
import random
import pdb

DELIM = ','
QCHAR = '"'

TST_F = "ip_hrt.csv"
NAME_IDX = 0
LVL_IDX = 1
DUR_IDX = 2

BASE_NODES = []

class FuncNode(object):
  def __init__(self, name, idx, duration, start=0):
    self.fname = name
    self.idx = idx
    self.duration = duration
    self.st = start
    self.children = []

  def add_child(self, cobj):
    cidx = cobj.idx
    # The starting pos of the first child is the same as the parent
    # Others start after the preceeding child ends
    if cidx:
      prev = self.children[cidx - 1]
      cobj.st = prev.st + prev.duration
    else:
      cobj.st = self.st
    self.children.insert(cidx, cobj)

def check_args():
    usage = "usage: python hrt -f <csv>"
    parser = OP(usage)
    parser.add_option("-f", dest="file", help="CSV input file")
    parser.add_option("-d", dest="debug", help="DEBUG", action="store_true", 
                            default=False)
    options, args = parser.parse_args()
    if (not options.file) and (not options.debug):
        parser.error(usage)
    return options
    
def read_csv(file):
  fh = open(file)
  rdr = csv.reader(fh)
  data = []
  for row in rdr:
    data.append(row[:DUR_IDX] + [int(row[DUR_IDX])])
  # Sort Data by levels
  data.sort(key=lambda x: len(x[LVL_IDX]))
  return data

def get_levels(csv_obj):
  lvls = csv_obj[LVL_IDX].split('.')
  return map(lambda x: int(x), lvls)

#TODO : treat base nodes as children of root node
def create_base_node(robj):
  global BASE_NODES

  cidx = get_levels(robj)[0] - 1
  st = 0
  if cidx:
    prev = BASE_NODES[cidx - 1]
    st = prev.st + prev.duration
  fobj = FuncNode(robj[NAME_IDX], cidx, robj[DUR_IDX], st)
  BASE_NODES.insert(cidx, fobj)

def create_child_node(robj):
  lvls = get_levels(robj)
  base_obj = BASE_NODES[lvls[0] - 1]
  for cur_lvl in lvls[1:-1]:
    base_obj = base_obj.children[cur_lvl - 1]
  fobj = FuncNode(robj[NAME_IDX], lvls[-1] - 1, robj[DUR_IDX])
  base_obj.add_child(fobj)

def create_nodes(data):
  for func in data:
    max_lvl = len(get_levels(func))
    if max_lvl == 1:
      create_base_node(func)
    else:
      create_child_node(func)

def draw_rect(ax, node, lvl):
    rw = 5
    color_d = {0 : "rgb",
               1 : "cmy",
               2 : "rgb"}
    frect = plt.Rectangle((node.st, lvl * rw), node.duration, rw,
            color=random.choice(color_d.get(lvl, "cmy")), ls='dashed')
    ax.annotate(node.fname, (node.st + node.duration/2, lvl * rw + rw/2),
                color='black', ha='center', va='center', fontsize=20)
    ax.add_artist(frect)

def draw(ax, node_list, lvl=0):
    for node in node_list:
      draw_rect(ax, node, lvl)
      if node.children:
        draw(ax, node.children, lvl + 1)

def plot():
    fig = plt.figure()
    ax = fig.add_subplot(111)
    draw(ax, BASE_NODES)
    
    plt.xlabel('Time')
    plt.title('Function Timelines')
    plt.xlim([0, BASE_NODES[-1].st + BASE_NODES[-1].duration + 50])
    plt.ylim([0, 30])
    plt.show()

def debug_mode():
    data = read_csv(TST_F)
    create_nodes(data)
    print "Checking csv struct"
    assert BASE_NODES[0].children[1].duration == 100
    assert BASE_NODES[0].children[1].fname == 'baz'
    assert BASE_NODES[0].children[1].st == 50
    assert BASE_NODES[0].children[1].children[1].fname == 'zar'
    assert BASE_NODES[0].children[1].children[1].st == 80
    print "CSV tree structure : pass"
    plot()

def main():
    options = check_args()
    if options.debug:
        debug_mode()
        return
    data = read_csv(options.file)
    create_nodes(data)
    plot()

if __name__ == "__main__":
    main()

