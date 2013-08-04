"""
Hierarchical Runtime Plotter
"""
import csv
import matplotlib
from optparse import OptionParser as OP
import pdb

DELIM = ','
QCHAR = '"'

TST_F = "ipfunc.csv"
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
    parser = OP()
    parser.add_option("-f", dest="file", help="CSV input file")
    options, args = parser.parse_args()
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

def main():
    options = check_args()
    data = read_csv(options.file)
    create_nodes(data)
    print data

if __name__ == "__main__":
    main()

