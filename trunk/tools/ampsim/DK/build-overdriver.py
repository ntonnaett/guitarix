import os
from analog import *

schema = "ColorsoundOverdriver.sch"
path = "tmp"
module_id = "overdriver"
mod = os.path.join(path, module_id+".so")


# create plugin
c1 = Circuit()
c1.plugindef = dk_simulator.PluginDef(module_id)
c1.plugindef.name = "Colorsound Overdriver"
c1.plugindef.description = "Colorsound Overdriver simulation"
c1.plugindef.category = "Distortion"
c1.plugindef.id = "overdriver"
c1.set_module_id(module_id)
c1.read_gschem(schema)
c1.create_faust_module()
